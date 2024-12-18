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

const int MX = 101;
int N, a[MX][MX], vis[MX][MX];

void dfs(int y, int x, int d)
{
	vis[y][x] = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (OOB(ny, nx, N, N))
		{
			continue;
		}
		if (!vis[ny][nx] and a[ny][nx] > d)
		{
			dfs(ny, nx, d);
		}
	}
}

int main()
{
	fastIO();

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> a[i][j];
		}
	}

	int ans = 0;
	for (int d = 1; d < MX; d++)
	{
		fill(&vis[0][0], &vis[0][0] + MX * MX, 0);
		int cnt = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (a[i][j] > d and !vis[i][j])
				{
					dfs(i, j, d);
					cnt++;
				}
			}
		}

		ans = max(ans, cnt);
	}

	cout << ans << '\n';
}