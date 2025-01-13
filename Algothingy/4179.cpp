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

const int MAX = 1111;
int r, c;
string graph[ MAX ];
int dist1[ MAX ][ MAX ];
int dist2[ MAX ][ MAX ];

int main()
{
	FastIO();

	ip2(r, c);
	for (int i = 0; i < r; i++)
	{
		cin >> graph[ i ];
		fill(dist1[ i ], dist1[ i ] + c, -1);
		fill(dist2[ i ], dist2[ i ] + c, -1);
	}

	queue<pii> q1, q2;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (graph[i][j] == 'F')
			{
				q1.push({ i, j });
				dist1[ i ][ j ] = 0;
			}
			if (graph[i][j] == 'J')
			{
				q2.push({ i, j });
				dist2[ i ][ j ] = 0;
			}
		}
	}

	while (!q1.empty())
	{
		auto cur = q1.front();
		q1.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = cur.X + dy[ i ];
			int nx = cur.Y + dx[ i ];
			if (OOB(ny, nx, r, c) or dist1[ ny ][ nx ] >= 0 or graph[ ny ][ nx ] == '#')
			{
				continue;
			}
			dist1[ ny ][ nx ] = dist1[ cur.X ][ cur.Y ] + 1;
			q1.push({ ny, nx });
		}
	}

	while (!q2.empty())
	{
		auto cur = q2.front();
		q2.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = cur.X + dy[ i ];
			int nx = cur.Y + dx[ i ];
			if (OOB(ny, nx, r, c))
			{
				op1l(dist2[ cur.X ][ cur.Y ] + 1);
				return 0;
			}
			if (dist2[ny][nx] >= 0 or graph[ny][nx] == '#')
			{
				continue;
			}
			if (dist1[ny][nx] != -1 and dist1[ny][nx] <= dist2[cur.X][cur.Y] + 1)
			{
				continue;
			}
			dist2[ ny ][ nx ] = dist2[ cur.X ][ cur.Y ] + 1;
			q2.push({ ny, nx });
		}
	}

	op1l("IMPOSSIBLE");
}
