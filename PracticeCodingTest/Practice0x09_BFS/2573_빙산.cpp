#include <bits/stdc++.h>
using namespace std;

const int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
bool OOB(int x, int y, int n, int m) { return x < 0 or x >= n or y < 0 or y >= m; }

int N, M;
int graph[333][333], vis[333][333];

void input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> graph[i][j];
		}
	}
}
void bfs(int i, int j)
{
	queue<pair<int, int>> q;
	vis[i][j] = 1;
	q.push({ i,j });
	while (!q.empty())
	{
		int x, y;
		tie(x, y) = q.front();
		q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = x + dx[dir], ny = y + dy[dir];
			if (OOB(nx,ny,N,M) or vis[nx][ny] == 1 or graph[nx][ny] == 0) continue;
			vis[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
}
void melt()
{
	int tmp[333][333] = {};
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (graph[i][j] == 0) continue;
			int cnt = 0;
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = i + dx[dir], ny = j + dy[dir];
				if (graph[nx][ny] == 0) cnt++;
			}
			tmp[i][j] = max(0, graph[i][j] - cnt);
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			graph[i][j] = tmp[i][j];
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	input();
	int year = 0;
	while (true)
	{
		int state = 0;
		for (int i = 0; i < N; i++)
		{
			fill(vis[i], vis[i] + M, 0);
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (graph[i][j] != 0 and vis[i][j] == 0)
				{
					state++;
					bfs(i, j);
				}
			}
		}
		if (state == 0) { cout << 0; break; }
		if (state >= 2) { cout << year; break; }
		melt();		
		year++;
	}
}