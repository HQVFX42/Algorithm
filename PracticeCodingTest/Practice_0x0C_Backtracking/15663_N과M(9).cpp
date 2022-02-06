// 1s, 512MB
// 1 <= M <= N <= 8
#include <bits/stdc++.h>
using namespace std;

int arr[8], num[8];
bool bUsed[8];

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
	int tmp = 0;
	for (int i = 0; i < n; i++)
	{
		if (bUsed[i] == false && tmp != num[i])	// 이전 수열의 마지막 항과 새로운 수열의 마지막 항이 같으면 중복수열
		{
			bUsed[i] = true;
			arr[k] = num[i];
			tmp = arr[k];
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