#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[502][502] =
{
 {1,1,1,0,1,0,0,0,0,0},
 {1,0,0,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0}
};
bool vis[502][502];
int n = 7, m = 10;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	queue < pair<int, int>> q;
	vis[0][0] = 1;		// (0,0) 방문
	q.push({ 0,0 });	// 큐에 시작점 삽입
	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();
		cout << '(' << cur.X << ", " << cur.Y << ") -> ";
		for (int dir = 0; dir < 4; dir++)		// 상하좌우 칸 탐색
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];			// nx, ny에 dir에 정한 방향의 인접한 칸 좌표
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)		// 범위 밖일 경우 패스
			{
				continue;
			}
			if (vis[nx][ny] || board[nx][ny] != 1)			// 이미 방문했거나 파랑칸이 아닐 경우
			{
				continue;
			}
			vis[nx][ny] = 1;	// nx, ny 방문
			q.push({ nx,ny });
		}
	}
}