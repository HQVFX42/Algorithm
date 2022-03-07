#include <bits/stdc++.h>
using namespace std;

int graph[111][111], vis[111];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		graph[x][y] = 1;
		graph[y][x] = 1;
	}

	queue<int> q;
	q.push(1);
	vis[1] = 1;
	int ans = 0;
	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (int i = 1; i <= n; i++)
		{
			if (graph[cur][i] == 1 and vis[i] == 0)
			{
				q.push(i);
				vis[i] = 1;
				ans++;
			}
		}
	}
	cout << ans;
}