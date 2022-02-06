// 1s, 512MB
// 1<= M <= N <= 8
#include<bits/stdc++.h>
using namespace std;

int arr[8], num[8];

void funcRecursive(int k, int n, int m, int st)
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
	int tmp = 0;
	for (int i = st; i < n; i++)
	{
		if (tmp != num[i])
		{
			arr[k] = num[i];
			tmp = arr[k];
			funcRecursive(k + 1, n, m, i + 1);
		}
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
	funcRecursive(0, n, m, 0);
}