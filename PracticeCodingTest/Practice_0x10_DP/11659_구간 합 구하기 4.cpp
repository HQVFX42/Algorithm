#include <bits/stdc++.h>
using namespace std;

int arr[111111], d[111111];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		d[i] = d[i - 1] + arr[i];
	}
	while (m--)
	{
		int i, j;
		cin >> i >> j;
		cout << d[j] - d[i - 1] << '\n';
	}
}