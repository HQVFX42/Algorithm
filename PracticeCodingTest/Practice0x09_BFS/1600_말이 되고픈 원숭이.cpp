#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
bool OOB(int x, int y, int n, int m) { return x < 0 or x >= n or y < 0 or y >= m; }
void fastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

const int ddx[] = { 1,2,2,1,-1,-2,-2,-1 }, ddy[] = { 2,1,-1,-2,-2,-1,1,2 };
int graph[222][222], dist[222][222][33];
queue<tuple<int, int, int, int>> q;

int main()
{
	fastIO();
	int k, w, h;
	cin >> k >> w >> h;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> graph[i][j];
		}
	}

	dist[0][0][0] = 1;
	q.push({ 0,0,0,0 });
	while (!q.empty())
	{
		int x, y, cnt, ans;
		tie(x, y, cnt, ans) = q.front(); q.pop();
		if (x == h - 1 and y == w - 1)
		{
			cout << ans;
			return 0;
		}
		if (cnt < k)
		{
			for (int dir = 0; dir < 8; dir++)
			{
				int nx = x + ddx[dir], ny = y + ddy[dir];
				if (OOB(nx, ny, h, w) or graph[nx][ny] == 1 or dist[nx][ny][cnt + 1] == 1) continue;
				dist[nx][ny][cnt + 1] = 1;
				q.push({ nx,ny,cnt + 1,ans + 1 });
			}
		}
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = x + dx[dir], ny = y + dy[dir];
			if (OOB(nx, ny, h, w) or graph[nx][ny] == 1 or dist[nx][ny][cnt] == 1) continue;
			dist[nx][ny][cnt] = 1;
			q.push({ nx,ny,cnt,ans + 1 });
		}
	}
	cout << -1;
}