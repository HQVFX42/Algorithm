#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	int arr[24] = {};
	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		arr[a]++;
	}
	for (int i = 1; i <= 23; i++)
	{
		cout << arr[i] << ' ';
	}
}