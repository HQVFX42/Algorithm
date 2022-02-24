#include <bits/stdc++.h>
using namespace std;

int n, arr[1000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << '\n';
	}
}