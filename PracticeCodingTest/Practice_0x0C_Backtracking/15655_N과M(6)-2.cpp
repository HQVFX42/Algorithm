#include<bits/stdc++.h>
using namespace std;

int n, m, arr[8];

void dfs2()
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
				cout << arr[i] << ' ';
			}
		}
		cout << '\n';
	} while (next_permutation(v.begin(), v.end()));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	dfs2();
}