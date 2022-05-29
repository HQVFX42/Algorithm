#include <bits/stdc++.h>
using namespace std;

void fastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int main()
{
	fastIO();
	int n, k;
	cin >> n >> k;
	int tmp, sum[111111] = {}, ans = -11111111;
	for (int i = 1; i <= n; i++)
	{
		cin >> tmp;
		sum[i] = sum[i - 1] + tmp;
	}
	for (int i = k; i <= n; i++)
	{
		ans = max(ans, sum[i] - sum[i - k]);
	}
	cout << ans;
}