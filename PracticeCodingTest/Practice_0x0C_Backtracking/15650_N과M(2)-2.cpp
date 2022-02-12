#include <bits/stdc++.h>
using namespace std;

void dfs2(int depth, int n, int m)
{
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		v.push_back(i < m ? 0 : 1);
	}
	do
	{
		for (int i = 0; i < n; i++)
		{
			if (v[i] == 0)
			{
				cout << i + 1 << ' ';
			}
		}
		cout << '\n';
	} while (next_permutation(v.begin(), v.end()));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;
	dfs2(0, N, M);
}