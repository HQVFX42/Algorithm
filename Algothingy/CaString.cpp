#include <iostream>

int CaStrLen(char* str)
{
	char* p = str;
	while (*p)
	{
		p++;
	}
	return p - str;
}

char* CaStrCpy(char* dest, const char* src)
{
	char* result = dest;

	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = 0;

	return result;
}

char* CaStrCat(char* dest, const char* src)
{
	char* result = dest;

	while (*dest)
	{
		dest++;
	}

	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}

	return result;
}

char* CaStrReverse(char* str)
{
    char* start = str;
    char* end = str;

    // 문자열 끝까지 이동
    while (*end)
    {
        end++;
    }
    end--; // 널 문자 이전 문자로 이동

    // 양쪽에서 가운데로 이동하며 문자 교환
    while (start < end)
    {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }

    return str;
}

int main()
{
	// 문자열 길이 계산
	char str[] = "Hello World!";
	int length = CaStrLen(str);
	std::cout << "Length of \"" << str << "\": " << length << std::endl;

	// 문자열 역순으로 변경
	std::cout << "Original: " << str << std::endl;
	CaStrReverse(str);
	std::cout << "Reversed: " << str << std::endl;

	// 문자열 복사
	char str2[22] = "";
	CaStrCpy(str2, str);
	std::cout << "Copied: " << str2 << std::endl;

	// 문자열 연결
	char str3[ 50 ] = "Hello";
	CaStrCat(str3, "World!");
	std::cout << "Concatenated: " << str3 << std::endl;

	return 0;
}