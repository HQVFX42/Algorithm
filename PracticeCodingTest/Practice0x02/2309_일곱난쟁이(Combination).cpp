#include <bits/stdc++.h>
using namespace std;

//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int heigt[9], result[7];
//
//	for (int i = 0; i < 9; i++)
//	{
//		cin >> heigt[i];
//	}
//
//	for (int a = 0; a < 8; a++)
//	{
//		int total = 0;
//
//		for (int b = a+1; b < 9; b++)
//		{
//			total = 0;
//
//			for (int c = 0, i =0 ; c < 9; c++)
//			{
//				if (c != a && c != b)
//				{
//					result[i++] = heigt[c];
//				}
//			}
//			for (int i = 0; i < 7; i++)
//			{
//				total += result[i];
//			}
//
//			if (total == 100)
//			{
//				break;
//			}
//		}
//		if (total == 100)
//		{
//			break;
//		}
//	}
//	sort(result, result + 7);
//	for (int i = 0; i < 7; i++)
//	{
//		cout << result[i] << "\n";
//	}
//}

int arr[9], sum;
bool isFind;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 9; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (sum - (arr[i] + arr[j]) == 100 && isFind == false)
			{
				arr[i] = -1;
				arr[j] = -1;
				isFind = true;
				break;
			}
		}
	}
	sort(arr, arr + 9);
	for (int i = 2; i < 9; i++) cout << arr[i] << '\n';
}