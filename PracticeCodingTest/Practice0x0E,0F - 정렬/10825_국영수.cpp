#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<tuple<int, int, int, string>> v;
	for (int i = 0; i < n; i++)
	{
		string name;
		int k, e, m;
		cin >> name >> k >> e >> m;
		v.push_back({ -k,e,-m,name });
	}
	sort(v.begin(), v.end());
	for (auto& [k, e, m, name] : v)
	{
		cout << name << '\n';
	}
}