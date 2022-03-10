#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
bool OOB(int x, int y, int n, int m) { return x < 0 or x >= n or y < 0 or y >= m; }
void fastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int graph[111][111], vis[111][111], dist[111][111];
int n;

int main()
{
	fastIO();
	queue<pii> qLand, qBridge;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> graph[i][j];
		}
	}

	int landNum = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (graph[i][j] == 0 or vis[i][j] == 1) continue;
			qLand.push({ i,j });
			vis[i][j] = 1;
			while (!qLand.empty())
			{
				int x, y;
				tie(x, y) = qLand.front(); qLand.pop();
				graph[x][y] = landNum;
				for (int dir = 0; dir < 4; dir++)
				{
					int nx = x + dx[dir], ny = y + dy[dir];
					if (OOB(nx, ny, n, n) or graph[nx][ny] == 0 or vis[nx][ny] == 1) continue;
					qLand.push({ nx,ny });
					vis[nx][ny] = true;
				}
			}
			landNum++;
		}
	}

	for (int i = 0; i < n; i++) fill(dist[i], dist[i] + n, -1);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (graph[i][j] != 0)
			{
				qBridge.push({ i,j });
				dist[i][j] = 0;
			}
		}
	}

	int ans = 0x0f0f0f0f;
	while (!qBridge.empty())
	{
		int x, y;
		tie(x, y) = qBridge.front(); qBridge.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = x + dx[dir], ny = y + dy[dir];
			if (OOB(nx, ny, n, n) or graph[nx][ny] == graph[x][y]) continue;
			if (graph[nx][ny] != 0)
			{
				ans = min(ans, dist[x][y] + dist[nx][ny]);
			}
			else
			{
				graph[nx][ny] = graph[x][y];
				dist[nx][ny] = dist[x][y] + 1;
				qBridge.push({ nx,ny });
			}
		}
	}
	cout << ans;
}