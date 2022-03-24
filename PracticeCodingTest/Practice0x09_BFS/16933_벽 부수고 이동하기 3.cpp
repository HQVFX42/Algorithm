#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
typedef tuple<int, int, int, int> tiiii;

const int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
bool OOB(int x, int y, int n, int m) { return x < 0 or x >= n or y < 0 or y >= m; }
void fastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int main()
{
	fastIO();
	int n, m, k;
	cin >> n >> m >> k;

	string graph[1111] = {};
	int dist[11][11][11][2] = {};
	for (int i = 0; i < n; i++) cin >> graph[i];

	queue<tiiii> q;
	q.push({ 0,0,0,0 });
	dist[0][0][0][0] = 1;
	while (!q.empty())
	{
		auto [x, y, z, bFlag] = q.front(); q.pop();
		if (x == n - 1 and y == m - 1)
		{
			cout << dist[x][y][z][bFlag];
			return 0;
		}
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = x + dx[dir], ny = y + dy[dir], nz = z, nf = 1 - bFlag;
			if (OOB(nx, ny, n, m)) continue;
			if (graph[nx][ny] == '1' and nf == 0) nz++;
			if (nz > k or dist[nx][ny][nz] > 0) continue;
			q.push({ nx,ny,nz, nf });
			dist[nx][ny][nz][nf] = dist[x][y][z][bFlag] + 1;
		}
	}
	cout << -1;
}