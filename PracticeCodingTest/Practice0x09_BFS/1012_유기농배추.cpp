#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[51][51];
bool hasVisited[51][51];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int m, n, k;
queue<pair<int, int>> q;

void bfs(int x, int y)
{
	q.push({ x,y });
	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();
		hasVisited[x][y] = true;
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (hasVisited[nx][ny] || board[nx][ny] != 1) continue;
			hasVisited[nx][ny] = true;
			q.push({ nx,ny });
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--)
	{
		cin >> m >> n >> k;
		int x, y;
		for (int i = 0; i < k; i++)
		{
			cin >> x >> y;
			board[y][x] = 1;
		}
		int res = 0;	//지렁이 개수
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (board[i][j] == 1 && !hasVisited[i][j])
				{
					bfs(i, j);
					res++;
				}
			}
		}
		cout << res << "\n";
		for (int i = 0; i < n; i++)
		{
			fill(board[i], board[i] + m, 0);
			fill(hasVisited[i], hasVisited[i] + m, false);
		}
	}
	return 0;
}
