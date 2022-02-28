#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, c;
	cin >> n >> c;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		bool flag = false;
		for (auto& j : v)
		{
			if (j.first == tmp)
			{
				flag = true;
				j.second++;
				break;
			}
		}
		if (!flag) v.push_back({ tmp, 1 });
	}
	stable_sort(v.begin(), v.end(), [](const pair<int, int>& lhs, const pair<int, int>& rhs)
		{
			return lhs.second > rhs.second;
		});
	for (auto& i : v) while (i.second--) cout << i.first << ' ';
}