#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
bool OOB(int x, int y, int n, int m) { return x < 0 or x >= n or y < 0 or y >= m; }
void fastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int n, m, k;
string graph[1111];
int dist[1111][1111][11];

int main()
{
	fastIO();
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> graph[i];
	}
	queue<tuple<int, int, int>> q;
	q.push({ 0,0,0 });
	dist[0][0][0] = 1;
	while (!q.empty())
	{
		auto [x, y, z] = q.front(); q.pop();
		if (x == n - 1 and y == m - 1)
		{
			cout << dist[x][y][z];
			return 0;
		}
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = x + dx[dir], ny = y + dy[dir], nz = z;
			if (OOB(nx, ny, n, m)) continue;
			if (graph[nx][ny] == '1') nz++;
			if (nz > k or dist[nx][ny][nz] > 0) continue;
			dist[nx][ny][nz] = dist[x][y][z] + 1;
			q.push({ nx,ny,nz });
		}
	}
	cout << -1;
}