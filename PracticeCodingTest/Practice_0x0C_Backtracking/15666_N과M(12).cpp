// 2s, 512MB
// 1 <= M <= N <= 8
#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[8], num[8];

void funcRecursive(int k, int st)
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
	int prev = 0;
	for (int i = st; i < n; i++)
	{
		if (prev != num[i])
		{
			arr[k] = num[i];
			prev = arr[k];
			funcRecursive(k + 1, i);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	sort(num, num + n);
	funcRecursive(0, 0);
}