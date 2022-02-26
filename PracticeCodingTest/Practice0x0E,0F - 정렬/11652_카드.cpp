#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	map<long long, int> m;
	while (n--)
	{
		long long tmp;
		cin >> tmp;
		m[tmp]++;
	}
	int cnt = 0;
	long long ans = 0;
	for (auto& i : m)
	{
		if (cnt < i.second)
		{
			ans = i.first;
			cnt = i.second;
		}
		else if (cnt == i.second and ans > i.first) ans = i.first;
	}
	cout << ans;
}