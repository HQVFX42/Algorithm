#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += i;
		if (ans >= n)
		{
			cout << ans;
			break;
		}
	}
}