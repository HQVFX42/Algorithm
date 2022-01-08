#include <bits/stdc++.h>
using namespace std;

string board[1002];
int dist1[1002][1002], dist2[1002][1002];
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
int n, m;
queue<pair<int, int>> q1, q2;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> board[i];
		fill(dist1[i], dist1[i] + m, -1);
		fill(dist2[i], dist2[i] + m, -1);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 'F')
			{
				q1.push({ i,j });
				dist1[i][j] = 0;
			}
			if (board[i][j] == 'J')
			{
				q2.push({ i,j });
				dist2[i][j] = 0;
			}
		}
	}

	while (!q1.empty())
	{
		auto cur = q1.front(); q1.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.first + dx[dir], ny = cur.second + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			{
				continue;
			}
			if (dist1[nx][ny] >= 0 || board[nx][ny] == '#')
			{
				continue;
			}
			dist1[nx][ny] = dist1[cur.first][cur.second] + 1;
			q1.push({ nx, ny });
		}
	}

	while (!q2.empty())
	{
		auto cur = q2.front(); q2.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.first + dx[dir], ny = cur.second + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			{
				cout << dist2[cur.first][cur.second] + 1;
				return 0;
			}
			if (dist2[nx][ny] >= 0 || board[nx][ny] == '#')
			{
				continue;
			}
			if (dist1[nx][ny] != -1 && dist2[nx][ny] + 1 >= dist1[nx][ny])
			{
				continue;
			}
			dist2[nx][ny] = dist2[cur.first][cur.second] + 1;
			q2.push({ nx, ny });
		}
	}

	cout << "IMPOSSIBLE";
}