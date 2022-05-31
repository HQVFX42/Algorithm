#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

void fastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }
const int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
bool OOB(int x, int y, int n, int m) { return x < 0 or x >= n or y < 0 or y >= m; }

string graph[111];
int dist[111][111];

int main()
{
	fastIO();
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> graph[i];
	}
	queue<pii> q;
	q.push({ 0,0 });
	dist[0][0] = 1;
	while (!q.empty())
	{
		int x, y;
		tie(x, y) = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = x + dx[dir], ny = y + dy[dir];
			if (OOB(nx, ny, n, m) or dist[nx][ny] or graph[nx][ny] == '0') continue;
			q.push({ nx,ny });
			dist[nx][ny] = dist[x][y] + 1;
		}
	}
	if (n > 1 and m > 1)
	{
		cout << dist[n - 1][m - 1];
	}
}