#include <bits/stdc++.h>
using namespace std;

int s[13], k;

void dfs2()
{
	vector<int> v;
	for (int i = 0; i < k; i++)
	{
		v.push_back(i < 6 ? 0 : 1);
	}
	do
	{
		for (int i = 0; i < k; i++)
		{
			if (v[i] == 0)
			{
				cout << s[i] << ' ';
			}
		}
		cout << '\n';
	} while (next_permutation(v.begin(), v.end()));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while (cin >> k && k)
	{
		for (int i = 0; i < k; i++)
		{
			cin >> s[i];
		}
		dfs2();
		cout << '\n';
	}
}