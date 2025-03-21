#include <iostream>
using namespace std;

int bubbleSort(int arr[], int n)
{
    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[ j ] > arr[ j + 1 ])
            {
                // 인접한 두 원소를 교환
                int temp = arr[ j ];
                arr[ j ] = arr[ j + 1 ];
                arr[ j + 1 ] = temp;
                cnt++;
            }
        }
    }
    
    return cnt;
}

int optimizedBubbleSort(int arr[], int n)
{
    bool swapped;
    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[ j ] > arr[ j + 1 ])
            {
                // 인접한 두 원소를 교환
                int temp = arr[ j ];
                arr[ j ] = arr[ j + 1 ];
                arr[ j + 1 ] = temp;
                cnt++;
                swapped = true;
            }
        }
        // 교환이 일어나지 않았다면 이미 정렬된 상태
        if (!swapped) break;
    }

    return cnt;
}


int main()
{
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int n = sizeof(arr) / sizeof(arr[ 0 ]);

    int a1 = bubbleSort(arr, n);
    int a2 = optimizedBubbleSort(arr, n);

    cout << "sorted: ";
    for (int i = 0; i < n; i++)
        cout << arr[ i ] << " ";
    cout << endl;

    cout << a1 << " " << a2;

    return 0;
}
