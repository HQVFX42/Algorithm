#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int d[11] = {};
	d[1] = 1, d[2] = 2, d[3] = 4;
	for (int i = 4; i < 11; i++)
	{
		d[i] = d[i - 1] + d[i - 2] + d[i - 3];
	}

	int TC;
	cin >> TC;
	while (TC--)
	{
		int n;
		cin >> n;
		cout << d[n] << '\n';
	}
}