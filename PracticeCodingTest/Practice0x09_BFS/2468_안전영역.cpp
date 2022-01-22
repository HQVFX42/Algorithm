#include <bits/stdc++.h>
using namespace std;

int board[102][102];
int vis[102][102];
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
int n;
queue<pair<int, int>> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}

	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] != 0 || vis[i][j] == 0)
			{
				while (!q.empty())
				{
					auto cur = q.front();	q.pop();
					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.first + dx[dir], ny = cur.second + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						if (vis[nx][ny] == 0 && board[nx][ny] != 0) continue;
					}
				}
			}
		}
	}
}