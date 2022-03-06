#include <bits/stdc++.h>
using namespace std;

int n, m, v;
int graph[1111][1111], vis[1111];

void dfs(int index)
{
	cout << index << ' ';
	vis[index] = true;
	for (int nxt = 1; nxt <= n; nxt++)
	{
		if (graph[index][nxt] == 1 and vis[nxt] == false)
		{
			dfs(nxt);
		}
	}
}

void bfs(int st)
{
	queue<int> q;
	q.push(st);
	vis[st] = true;
	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();
		for (int nxt = 1; nxt <= n; nxt++)
		{
			if (graph[cur][nxt] == 1 and vis[nxt] == false)
			{
				q.push(nxt);
				vis[nxt] = true;				
			}
		}
		cout << cur << ' ';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> v;
	for (int i = 0; i < m; i++)
	{
		int from, to;
		cin >> from >> to;
		graph[from][to] = 1;
		graph[to][from] = 1;
	}
	dfs(v);
	cout << '\n';
	fill(vis, vis + n + 1, 0);
	bfs(v);
}