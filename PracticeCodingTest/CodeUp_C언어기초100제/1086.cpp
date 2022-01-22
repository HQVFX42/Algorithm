#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	double w, b, h;
	cin >> w >> b >> h;
	cout << fixed << setprecision(2) << (w * b * h) / (8 * 1024 * 1024) << " MB";
}