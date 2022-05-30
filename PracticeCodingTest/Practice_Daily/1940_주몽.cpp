#include <bits/stdc++.h>
using namespace std;

void fastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int n, m, ans;
vector<int> v;

int main()
{
	fastIO();
	cin >> n;
	cin >> m;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	int st = 0, en = n - 1;
	while (st < en)
	{
		if (v[st] + v[en] == m)
		{
			st++;
			en--;
			ans++;
		}
		if (v[st] + v[en] > m)
		{
			en--;
		}
		if (v[st] + v[en] < m)
		{
			st++;
		}
	}
	cout << ans;
}