#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
bool OOB(int x, int y, int n, int m) { return x < 0 or x >= n or y < 0 or y >= m; }
void fastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int graph[111][111], vis[111][111];

void init(int n)
{
	for (int i = 0; i < n; i++) { fill(vis[i], vis[i] + n, 0); }
}

int main()
{
	fastIO();
	int n;
	cin >> n;
	int maxHeight = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> graph[i][j];
			maxHeight = max(graph[i][j], maxHeight);
		}
	}

	queue<pii> q;
	int ans = 0;
	for (int height = 0; height <= maxHeight; height++)
	{
		init(n);
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (graph[i][j] > height and vis[i][j] == 0)
				{
					vis[i][j] = 1;
					q.push({ i,j });
					while (!q.empty())
					{
						int x, y;
						tie(x, y) = q.front(); q.pop();
						for (int dir = 0; dir < 4; dir++)
						{
							int nx = x + dx[dir], ny = y + dy[dir];
							if (OOB(nx,ny,n,n))
							{
								continue;
							}
							if (vis[nx][ny] == 0 and graph[nx][ny] > height)
							{
								vis[nx][ny] = 1;
								q.push({ nx,ny });
							}
						}
					}
					cnt++;
				}
			}
		}
		ans = max(cnt, ans);
	}

	cout << ans;
}