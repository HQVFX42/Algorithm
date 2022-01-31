#include <bits/stdc++.h>
using namespace std;
// R : 1s, 512MB
// 1 <= M <= N <= 8
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

	for (int i = 1; i <= n; i++)
	{
		if (bUsed[i] == false)
		{
			arr[k] = i;
			bUsed[i] = true;
			funcRecursive(k + 1, n, m);
			bUsed[i] = false;	// k번째 수를 i로 정한 모든 경우에 대해 다 확인하면 i를 다시 미사용으로 
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