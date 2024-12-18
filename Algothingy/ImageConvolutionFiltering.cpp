#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

// 이미지 구조체
struct Image
{
    int width, height, channels;
    std::vector<unsigned char> data;
};

// 이미지 로드 함수
Image loadImage(const char * filename)
{
    Image img;
    unsigned char * data = stbi_load(filename, &img.width, &img.height, &img.channels, 0);
    if (data)
    {
        img.data = std::vector<unsigned char>(data, data + img.width * img.height * img.channels);
        stbi_image_free(data);
    }
    return img;
}

// 이미지 저장 함수
void saveImage(const char * filename, const Image & img)
{
    stbi_write_png(filename, img.width, img.height, img.channels, img.data.data(), img.width * img.channels);
}

// 합성곱 필터 적용 함수
Image applyFilter(const Image & src, const std::vector<float> & kernel, int kernelSize)
{
    Image dst = src;
    int halfKernel = kernelSize / 2;

    for (int y = halfKernel; y < src.height - halfKernel; ++y)
    {
        for (int x = halfKernel; x < src.width - halfKernel; ++x)
        {
            for (int c = 0; c < src.channels; ++c)
            {
                float sum = 0.0f;
                for (int ky = -halfKernel; ky <= halfKernel; ++ky)
                {
                    for (int kx = -halfKernel; kx <= halfKernel; ++kx)
                    {
                        int idx = ((y + ky) * src.width + (x + kx)) * src.channels + c;
                        sum += src.data[ idx ] * kernel[ (ky + halfKernel) * kernelSize + (kx + halfKernel) ];
                    }
                }
                int idx = (y * src.width + x) * src.channels + c;
                dst.data[ idx ] = std::clamp(static_cast< int >(sum), 0, 255);
            }
            dst.data[ (y * src.width + x) * src.channels + 3 ] = src.data[ (y * src.width + x) * src.channels + 3 ];
        }
    }
    return dst;
}

// 샤프닝 필터
Image sharpen(const Image & src)
{
    std::vector<float> kernel =
    {
        0, -1, 0,
        -1, 5, -1,
        0, -1, 0
    };
    return applyFilter(src, kernel, 3);
}

// 간단한 엣지 검출 필터
Image edgeDetection(const Image & src)
{
    std::vector<float> kernel =
    {
        1, 0, -1,
        0,  0, 0,
        -1, 0, 1
    };
    return applyFilter(src, kernel, 3);
}

// 블러링 필터 (평균)
Image blur(const Image & src)
{
    std::vector<float> kernel(9, 1.0f / 9.0f);
    return applyFilter(src, kernel, 3);
}

int main()
{
    const char * inputFilename = "./Textures/input.jpg";
    Image img = loadImage(inputFilename);

    if (img.data.empty())
    {
        std::cout << "Failed to load image: " << inputFilename << std::endl;
        return -1;
    }

    Image sharpenedImg = sharpen(img);
    Image edgeImg = edgeDetection(img);
    Image blurredImg = blur(img);

    saveImage("sharpened.png", sharpenedImg);
    saveImage("edge.png", edgeImg);
    saveImage("blurred.png", blurredImg);

    std::cout << "Filtered images saved successfully." << std::endl;

    return 0;
}