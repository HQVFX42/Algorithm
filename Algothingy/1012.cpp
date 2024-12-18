#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ldb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

static bool OOB(int x, int y, int n, int m) { return x < 0 or x >= n or y < 0 or y >= m; }

void fastIO()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
}

const int MX = 55;
int n, m, k, a[MX][MX];
bool vis[MX][MX];

void dfs(int y, int x)
{
	vis[y][x] = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (OOB(ny, nx, n, m))
		{
			continue;
		}
		if (a[ny][nx] == 1 and !vis[ny][nx])
		{
			dfs(ny, nx);
		}
	}
}

int main()
{
	fastIO();

	int TC = 0;
	cin >> TC;

	while (TC--)
	{
		fill(&a[0][0], &a[0][0] + MX * MX, 0);
		fill(&vis[0][0], &vis[0][0] + MX * MX, 0);

		cin >> m >> n >> k;
		for (int i = 0; i < k; i++)
		{
			int x, y;
			cin >> x >> y;
			a[y][x] = 1;
		}

		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[i][j] == 1 && !vis[i][j])
				{
					dfs(i, j);
					ans++;
				}
			}
		}

		cout << ans << '\n';
	}
}