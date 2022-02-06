// 1s, 512MB
// 1 <= M <= N 8
#include <bits/stdc++.h>
using namespace std;

int arr[10];
int num[10];
bool bUsed[10];

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
	int st = 0;
	if (k != 0) st = arr[k - 1] + 1;
	for (int i = st; i < n; i++)
	{
		if (bUsed[i] == false)
		{
			arr[k] = i;
			bUsed[i] = true;
			funcRecursive(k + 1, n, m);
			bUsed[i] = false;
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
	funcRecursive(0, n, m);
}