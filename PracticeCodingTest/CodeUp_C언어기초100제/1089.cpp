#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, d, n;
	cin >> a >> d >> n;

	int ans = a;
	for (int i = 0; i < n - 1; i++)
	{
		ans += d;
	}
	cout << ans;
}