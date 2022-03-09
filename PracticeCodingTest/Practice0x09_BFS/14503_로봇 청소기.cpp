#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

#define X first
#define Y second
#define rep(i,a,b) for(int i = a; i < b; i++)
#define ip1(a) cin >> a
#define ip2(a,b) cin >> a >> b
#define op1(a) cout << a << ' '
#define op2(a,b) cout << a << ' ' << b
#define op1l(a) cout << a << '\n'
#define op2l(a) cout << a << ' ' << b << '\n'
#define opl cout << '\n'
const int dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };
bool OOB(int x, int y, int n, int m) { return x < 0 or x >= n or y < 0 or y >= m; }

int n, m;
int graph[55][55], vis[55][55];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ip2(n, m);
	int r, c, d;
	cin >> r >> c >> d;
	rep(i, 0, n) rep(j, 0, m) ip1(graph[i][j]);

	int cnt = 0;
	while (true)
	{
		if (vis[r][c] == 0)
		{
			vis[r][c] = 1;
			cnt++;
		}
		bool flag = false;
		rep(dir, 0, 4)
		{
			d = (d + 3) % 4;
			int nx = r + dx[d], ny = c + dy[d];
			if (OOB(nx, ny, n, m) or graph[nx][ny] == 1 or vis[nx][ny] == 1) continue;
			r += dx[d];
			c += dy[d];
			flag = true;
			break;
		}
		if (!flag)
		{	// ÈÄÁø
			int nd = (d + 2) % 4;
			int nx = r + dx[nd], ny = c + dy[nd];
			if (OOB(nx, ny, n, m) or graph[nx][ny] == 1) break;
			r += dx[nd];
			c += dy[nd];
		}
	}
	op1(cnt);
}