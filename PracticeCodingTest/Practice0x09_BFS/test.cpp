#include <bits/stdc++.h>
using namespace std;

char board[1002][1002];
int dist1[1002][1002], dist2[1002][1002];
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
int TC, w, h;
bool escape;
queue<pair<int, int>> q1, q2;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> TC;
	while (TC--)
	{
		escape = false;
		q1 = {}, q2 = {};	//queue init
		cin >> h >> w;
		for (int i = 0; i < w; i++)
		{
			for (int j = 0; j < h; j++)
			{
				dist1[i][j] = -1;
				dist2[i][j] = -1;				
				cin >> board[i][j];
				if (board[i][j] == '*')
				{
					dist1[i][j] = 0;
					q1.push({ i,j });
				}
				if (board[i][j] == '@')
				{
					dist2[i][j] = 0;
					q2.push({ i,j });
				}
			}
		}

		while (!q1.empty())
		{
			auto cur = q1.front();	q1.pop();
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = cur.first + dx[dir], ny = cur.second + dy[dir];
				if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
				if (dist1[nx][ny] >= 0 || board[nx][ny] == '#') continue;
				dist1[nx][ny] = dist1[cur.first][cur.second] + 1;
				q1.push({ nx, ny });
			}

		}

		while ((!q2.empty()) && (escape == false))
		{
			auto cur = q2.front(); q2.pop();
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = cur.first + dx[dir], ny = cur.second + dy[dir];
				if (nx < 0 || nx >= w || ny < 0 || ny >= h)
				{
					cout << dist2[cur.first][cur.second] + 1 << '\n';
					escape = true;
					break;
				}
				if (dist2[nx][ny] >= 0 || board[nx][ny] == '#') continue;
				if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.first][cur.second] + 1) continue;
				dist2[nx][ny] = dist2[cur.first][cur.second] + 1;
				q2.push({ nx, ny });
			}
		}

		if (escape == false) cout << "IMPOSSIBLE" << '\n';
	}
}