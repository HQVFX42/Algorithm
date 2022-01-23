#include <bits/stdc++.h>
using namespace std;

int board[102][102];
int vis[102][102];
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
int n;
queue<pair<int, int>> q;

void INIT()
{
	for (int i = 0; i < n; i++)
	{
		fill(vis[i], vis[i] + n, 0);
	}
}

void BFS(int i, int j, int height)
{
	vis[i][j] = 1;
	q.push({ i,j });
	while (!q.empty())
	{
		auto cur = q.front();	q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.first + dx[dir], ny = cur.second + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (vis[nx][ny] == 0 && board[nx][ny] > height)	// 방문하지 않았으면서, 침수되지 않았을 때
			{
				vis[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
	}
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	int maxHeight = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			maxHeight = max(board[i][j], maxHeight);	// 잠기는 최대 높이 저장
		}
	}
	// 0부터 최대높이까지 반복, 전체 BFS
	int maxCount = 0;
	for (int height = 0; height <= maxHeight; height++)
	{
		INIT();
		int count = 0;	// 0부터 최대높이까지 각각 최대 영역 개수 저장
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (vis[i][j] == 0 && board[i][j] > height)	// 방문 여부, 침수 여부
				{
					BFS(i,j,height);
					count++;
				}
			}
		}
		maxCount = max(count, maxCount);
	}
	cout << maxCount;
}