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

const int MAX = 111;
int n, m, vis[MAX][MAX], x, y;
string a[MAX];

void fastIO()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
}

int main()
{
	fastIO();

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	queue<pii> q;
	q.push({ 0, 0 });
	vis[0][0] = 1;

	while (!q.empty())
	{
		tie(y, x) = q.front();
		q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			if (ny < 0 or ny >= n or nx < 0 or nx >= m or a[ny][nx] == '0')
			{
				continue;
			}
			if (vis[ny][nx])
			{
				continue;
			}
			
			vis[ny][nx] = vis[y][x] + 1;
			q.push({ ny, nx });
		}
	}

	cout << vis[n - 1][m - 1];
}