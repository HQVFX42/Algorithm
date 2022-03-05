#include <bits/stdc++.h>
using namespace std;

int fibo(int n, int index)
{
	int f[44][2] = {};
	f[0][0] = f[1][1] = 1;
	for (int i = 2; i <= n; i++)
	{
		f[i][0] = f[i - 1][0] + f[i - 2][0];
		f[i][1] = f[i - 1][1] + f[i - 2][1];
	}
	return f[n][index];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int TC;
	cin >> TC;
	while (TC--)
	{
		int n;
		cin >> n;
		cout << fibo(n, 0) << ' ' << fibo(n, 1) << '\n';
	}
}