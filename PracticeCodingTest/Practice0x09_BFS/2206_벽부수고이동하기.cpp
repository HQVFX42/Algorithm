#include <bits/stdc++.h>
using namespace std;

char board[1000][1000];
int dist[1000][1000][2];
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
int N, M;
queue<tuple<int, int, int>> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	// INPUT
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
		}
	}
	// INIT
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			dist[i][j][0] = -1;
			dist[i][j][1] = -1;
		}
	}
	dist[0][0][0] = dist[0][0][1] = 1;
	q.push({ 0,0,0 });
	// BFS
	while (!q.empty())
	{
		int curX, curY, isBroken;
		tie(curX, curY, isBroken) = q.front();
		int nxt = dist[curX][curY][isBroken];
		if (curX == N - 1 && curY == M - 1)
		{
			cout << nxt;
			return 0;
		}
		q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = curX + dx[dir], ny = curY + dy[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
			{
				continue;
			}
			if (board[nx][ny] == '0' && dist[nx][ny][isBroken] == -1)
			{
				dist[nx][ny][isBroken] = nxt + 1;
				q.push({ nx,ny,isBroken });
			}
			// nx,ny를 부수는 경우
			if (!isBroken && board[nx][ny] == '1' && dist[nx][ny][1] == -1)
			{
				dist[nx][ny][1] = nxt + 1;
				q.push({ nx,ny,1 });
			}
		}
	}
	cout << -1;
}