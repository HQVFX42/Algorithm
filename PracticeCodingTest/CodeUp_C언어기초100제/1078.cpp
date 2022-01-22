#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i <= n; i++)
	{
		if ((i & 1) == 0)
		{
			ans += i;
		}
	}
	cout << ans;
}