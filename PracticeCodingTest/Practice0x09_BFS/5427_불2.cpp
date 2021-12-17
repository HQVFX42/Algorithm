#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int TC, w, h;
int board[1002][1002];
int visF[1002][1002];
int visS[1002][1002];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> TC;
	for (int t = 0; t < TC; t++)
	{
		bool canEscape = false;
		queue<pair<int, int>> qF = {}, qS = {};
		cin >> h >> w;
		for (int i = 0; i < w; i++)
		{
			fill(visF[i], visF[i] + h, 0);
			fill(visS[i], visS[i] + h, 0);
		}
		for (int i = 0; i < w; i++)
		{
			for (int j = 0; j < h; j++)
			{
				char c;
				cin >> c;
				if (c == '#')
				{
					board[i][j] = -1;
				}
				else
				{
					if (c == '@')
					{
						qS.push({ i,j });
						visS[i][j] = 1;
					}
					else if (c == '*')
					{
						qF.push({ i,j });
						visF[i][j] = 1;
					}
					board[i][j] = 0;
				}
			}
		}
		while (!qF.empty())
		{
			auto cur = qF.front();
			qF.pop();
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || w <= nx || ny < 0 || h <= ny) continue;
				if (board[nx][ny] == -1) continue;
				if (visF[nx][ny]) continue;
				visF[nx][ny] = visF[cur.X][cur.Y] + 1;
				qF.push({ nx,ny });
			}
		}
		while (!qS.empty() && !canEscape)
		{
			auto cur = qS.front();
			qS.pop();
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || w <= nx || ny < 0 || h <= ny)
				{
					cout << visS[cur.X][cur.Y] << "\n";
					canEscape = true;
					break;
				}
				if (board[nx][ny] == -1) continue;
				if (visS[nx][ny]) continue;
				if (visF[nx][ny] != 0 && visF[nx][ny] <= visS[cur.X][cur.Y] + 1) continue;
				visS[nx][ny] = visS[cur.X][cur.Y] + 1;
				qS.push({ nx,ny });
			}
		}
		if (!canEscape)
		{
			cout << "IMPOSSIBLE" << '\n';
		}
	}
}