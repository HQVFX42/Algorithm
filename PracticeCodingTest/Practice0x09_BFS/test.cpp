#include <bits/stdc++.h>
using namespace std;

char board[102][102];
bool hasVis[102][102];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
queue<pair<char, char >> q;
int n, ansN, ansY;

void bfs(int i, int j)
{
	q.push({ i,j });
	hasVis[i][j] = true;
	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
			{
				continue;
			}
			if (hasVis[nx][ny] == true || board[i][j] != board[nx][ny])
			{
				continue;
			}
			hasVis[nx][ny] = true;
			q.push({ nx,ny });
		}
	}
}
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
		
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (hasVis[i][j] == false)
			{
				ansN++;				
				bfs(i, j);
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		fill(hasVis[i], hasVis[i] + n, false);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == 'R')
			{
				board[i][j] = 'G';
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (hasVis[i][j] == false)
			{
				ansY++;
				bfs(i, j);
			}
		}
	}
	cout << ansN << ' ' << ansY;
}