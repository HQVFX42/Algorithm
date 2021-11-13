#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int arr[4];
	for (int i = 0; i < 3; i++)
	{
		cin >> arr[i];
	}
	int temp;
	//¹öºí O(n^2)
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3 - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		cout << arr[i] << " ";
	}
}