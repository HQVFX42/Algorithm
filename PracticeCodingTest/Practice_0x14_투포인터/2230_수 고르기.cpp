#include <bits/stdc++.h>
using namespace std;

void fastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int a[111111];

int main()
{
	fastIO();
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);

	int ans = 0x7fffffff;	// 최소값 설정을 위한 MAX
	int lp = 0, rp = 0;
	for (lp; lp < n; lp++)
	{
		while (rp < n and a[rp] - a[lp] < m)
		{
			rp++;
		}
		if (rp == n) break;
		ans = min(ans, a[rp] - a[lp]);
	}
	cout << ans;
}