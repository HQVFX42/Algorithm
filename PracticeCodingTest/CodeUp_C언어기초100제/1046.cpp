#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b, c;
	cin >> a >> b >> c;
	double ans = 0;
	ans = abs(abs(a + b) + c);
	cout << ans << "\n" << fixed << setprecision(1) << ans / 3;
}