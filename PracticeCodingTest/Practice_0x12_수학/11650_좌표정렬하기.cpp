#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (auto& i : v)
	{
		cin >> i.first >> i.second;
	}
	sort(v.begin(), v.end());
	for (auto i : v)
	{
		cout << i.first << ' ' << i.second << '\n';
	}
}