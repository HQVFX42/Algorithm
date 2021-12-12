#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[102][102][102];
int dist[102][102][102];
int n, m, h;
int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> m >> n >> h;
	queue<pair<pair<int, int>, int>> q;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				cin >> board[i][j][k];
				if (board[i][j][k] == 1)
				{
					q.push({ {i,j},k });
				}
				if (board[i][j][k] == 0)
				{
					dist[i][j][k] = -1;
				}
			}
		}
	}
	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();
		for (int dir = 0; dir < 6; dir++)
		{
			int nz = cur.X.X + dz[dir];
			int nx = cur.X.Y + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
			if (dist[nz][nx][ny] >= 0) continue;
			dist[nz][nx][ny] = dist[cur.X.X][cur.X.Y][cur.Y] + 1;
			q.push({ { nz,nx },ny });
		}
	}
	int ans = 0;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (dist[i][j][k] == -1)
				{
					cout << -1;
					return 0;
				}
				ans = max(ans, dist[i][j][k]);
			}
		}
	}
	cout << ans;
}