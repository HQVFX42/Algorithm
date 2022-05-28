#include <bits/stdc++.h>
using namespace std;

void fastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int cnt[111];

int main()
{
	fastIO();
	int a, b, c;
	cin >> a >> b >> c;
	for (int i = 0; i < 3; i++)
	{
		int t1, t2;
		cin >> t1 >> t2;
		for (int j = t1; j < t2; j++)
		{
			cnt[j]++;
		}
	}
	int ans = 0;
	for (int j = 1; j < 100; j++)
	{
		if (cnt[j])
		{
			if (cnt[j] == 1) ans += a;
			else if (cnt[j] == 2) ans += b * 2;
			else if (cnt[j] == 3) ans += c * 3;
		}
	}
	cout << ans;
}