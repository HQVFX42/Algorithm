#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define X first
#define Y second
#define rep(i,a,b) for(int i = a; i < b; i++)
#define ip1(a) cin >> a
#define ip2(a,b) cin >> a >> b
#define ops cout << ' '
#define op1(a) cout << a << ' '
#define op2(a,b) cout << a << ' ' << b
#define opl cout << '\n'
#define op1l(a) cout << a << '\n'
#define op2l(a,b) cout << a << ' ' << b << '\n'

const int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };

bool OOB(int x, int y, int n, int m) { return x < 0 or x >= n or y < 0 or y >= m; }
void FastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int n, m;
int vis[55][55];
string graph[55];
int result;

void BFS(int y, int x)
{
	memset(vis, 0, sizeof(vis));
	vis[y][x] = 1;
	queue<pii> q;
	q.push({ y, x });
	while (!q.empty())
	{
		tie(y, x) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (OOB(ny, nx, n, m) or vis[ny][nx] or graph[ny][nx] == 'W')
			{
				continue;
			}

			vis[ny][nx] = vis[y][x] + 1;
			q.push({ ny, nx });
			result = max(result, vis[ny][nx]);
		}
	}
}

int main()
{
	FastIO();

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> graph[i];
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (graph[i][j] == 'L')
			{
				BFS(i, j);
			}
		}
	}

	cout << result - 1;
}
