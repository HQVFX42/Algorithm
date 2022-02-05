// 1s, 512MB
// 1 <= M <= N <= 7
#include <bits/stdc++.h>
using namespace std;

int arr[10];

void funcRecursive(int k, int n, int m)
{
	if (k == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		arr[k] = i;
		funcRecursive(k + 1, n, m);
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	funcRecursive(0, n, m);
}