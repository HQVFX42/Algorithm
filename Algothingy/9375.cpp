#include <bits/stdc++.h>

using namespace std;

void fastIO()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
}

int main()
{
	fastIO();

	int tc = 0;
	cin >> tc;
	while (tc--)
	{
		int n = 0;
		cin >> n;

		map<string, int> map;
		for (int i = 0; i < n; i++)
		{
			string a;
			string b;
			cin >> a >> b;
			map[b]++;
		}

		long long result = 1;
		for (auto& i : map)
		{
			result *= (long long)i.second + 1;
		}
		result--;

		cout << result << '\n';
	}
}