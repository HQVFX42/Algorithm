#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long h, b, c, s;
	cin >> h >> b >> c >> s;
	double ans = (h * b * c * s) / (8 * 1024);
	cout << fixed << setprecision(1) << ans / 1024 << " MB";
}