#include <bits/stdc++.h>
using namespace std;

int dist[302][302];
int dx[8] = { 1,2,2,1,-1,-2,-2,-1 }, dy[8] = { 2,1,-1,-2,-2,-1,1,2 };
int TC, n, x, y, xx, yy;
queue<pair<int, int>>q;

void BFS()
{
	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 8; dir++)
		{
			int nx = cur.first + dx[dir], ny = cur.second + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (dist[nx][ny] >= 0) continue;
			dist[nx][ny] = dist[cur.first][cur.second] + 1;
			q.push({ nx,ny });
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> TC;
	while (TC--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			fill(dist[i], dist[i] + n, -1);
		}

		cin >> x >> y;
		dist[x][y] = 0;
		q.push({ x,y });
		BFS();
		cin >> xx >> yy;		
		cout << dist[xx][yy] << '\n';
	}
}