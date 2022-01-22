#include <bits/stdc++.h>
using namespace std;

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
	for (int i = 2; i < 9; i++)
	{
		cout << arr[i] << '\n';
	}
}