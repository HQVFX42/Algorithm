#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, m, d, n;
	cin >> a >> m >> d >> n;

	long long ans = a;
	for (int i = 0; i < n - 1; i++)
	{
		ans = ans * m + d;
	}
	cout << ans;
}