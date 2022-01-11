#include <bits/stdc++.h>
using namespace std;

int board[102][102][102], dist[102][102][102];
int dx[6] = { 1,-1,0,0,0,0 }, dy[6] = { 0,0,1,-1,0,0 }, dz[6] = { 0,0,0,0,1,-1 };
int m, n, h, ans;
queue<tuple<int, int, int>> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> m >> n >> h;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				cin >> board[j][k][i];
				if (board[j][k][i] == 1)
				{
					q.push({ j,k,i });
				}
				if (board[j][k][i] == 0)
				{
					dist[j][k][i] = -1;
				}
			}
		}
	}

	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 6; dir++)
		{
			int nx = get<0>(cur) + dx[dir], ny = get<1>(cur) + dy[dir], nz = get<2>(cur) + dz[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h)
			{
				continue;
			}
			if (dist[nx][ny][nz] >= 0)
			{
				continue;
			}
			dist[nx][ny][nz] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
			q.push({ nx,ny,nz });
		}
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (dist[j][k][i] == -1)
				{
					cout << -1;
					return 0;
				}
				ans = max(ans, dist[j][k][i]);
			}
		}
	}
	cout << ans;

	/*for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				cout << board[j][k][i];
			}
		}
	}*/
}