#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
bool OOB(int x, int y, int n, int m) { return x < 0 or x >= n or y < 0 or y >= m; }
void fastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int graph[55][55], vis[55][55];
queue<pii> q;

void bfs(int x, int y, int n, int m)
{
	while (!q.empty())
	{
		int x, y;
		tie(x, y) = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = x + dx[dir], ny = y + dy[dir];
			if (OOB(x, y, n, m) or graph[nx][ny] == 0 or vis[nx][ny] == 1) continue;
			q.push({ nx,ny });
			vis[nx][ny] = 1;
		}
	}
}

int main()
{
	fastIO();
	int TC;
	cin >> TC;
	while (TC--)
	{
		int n, m, k;
		cin >> n >> m >> k;
		for (int i = 0; i < k; i++)
		{
			int x, y;
			cin >> x >> y;
			graph[x][y] = 1;
		}

		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (graph[i][j] == 1 and vis[i][j] == 0)
				{
					q.push({ i,j });
					vis[i][j] = 1;
					bfs(i, j, n, m);
					ans++;
				}
			}
		}

		cout << ans << '\n';
	}
}