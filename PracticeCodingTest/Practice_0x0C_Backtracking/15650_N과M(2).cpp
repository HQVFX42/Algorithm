// 1s, 512MB
// 1 <= M <= 8
#include <bits/stdc++.h>
using namespace std;

int arr[10];
bool bUsed[10];

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
	int cnt = arr[k - 1] + 1;
	//int cnt = 1;
	//if(cnt != 0) cnt = arr[k - 1] + 1;
	for (int i = cnt; i <= n; i++)
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

	int N, M;
	cin >> N >> M;
	funcRecursive(0, N, M);
}