// 1s, 512MB
// 1<= M <= N <= 8
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
	int begin = 1;
	if (k != 0) begin = arr[k - 1];
	for (int i = begin; i <= n; i++)
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
	funcRecursive(0, n, m);
}