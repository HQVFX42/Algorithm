#include <bits/stdc++.h>
using namespace std;

void fastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int main()
{
	fastIO();
	int n;
	while (cin >> n)
	{
		int cnt = 1, ans = 1;
		while (true)
		{
			if (cnt % n == 0)
			{
				cout << ans << '\n';
				break;
			}
			else
			{
				cnt = cnt * 10 + 1;
				cnt %= n;
				ans++;
			}
		}
	}
}