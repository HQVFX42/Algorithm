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

const int MX = 111;
int a[MX][MX], vis[MX][MX];
int m, n, k;

int dfs(int y, int x)
{
	vis[y][x] = 1;
	int result = 1;
	for (int dir = 0; dir < 4; dir++)
	{
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (OOB(ny, nx, m, n) or vis[ny][nx] == 1)
		{
			continue;
		}
		if (a[ny][nx] == 1)
		{
			continue;
		}

		result += dfs(ny, nx);
	}

	return result;
}

int main()
{
	fastIO();

	cin >> m >> n >> k;

	while (k--)
	{
		int x, y, xx, yy;
		cin >> x >> y >> xx >> yy;
		for (int i = x; i < xx; i++)
		{
			for (int j = y; j < yy; j++)
			{
				a[j][i] = 1;
			}
		}
	}

	vi ans;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == 0 and vis[i][j] == 0)
			{
				ans.push_back(dfs(i, j));
			}
		}
	}

	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (auto& i : ans)
	{
		cout << i << ' ';
	}
}