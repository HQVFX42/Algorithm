// 1s, 512MB
// 1 <= M <= N <=7
#include <bits/stdc++.h>
using namespace std;

int arr[8], num[8];

void funcRecursive(int k, int n, int m)
{
	if (k == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << num[arr[i]] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++)
	{
		arr[k] = i;
		funcRecursive(k + 1, n, m);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	sort(num, num + n);
	funcRecursive(0, n, m);
}