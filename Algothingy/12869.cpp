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

int da[ 6 ][ 3 ] =
{
	{9, 3, 1},
	{9, 1, 3},
	{3, 1, 9},
	{3, 9, 1},
	{1, 3, 9},
	{1, 9, 3}
};

queue<tuple<int, int, int>> q;
int n, a[3], vis[66][66][66];

int BFS(int a, int b, int c)
{
	vis[ a ][ b ][ c ] = 1;
	q.push({ a, b, c });
	while (!q.empty())
	{
		int x, y, z;
		tie(x, y, z) = q.front();
		q.pop();

		if (vis[0][0][0])
		{
			break;
		}

		for (int i = 0; i < 6; i++) // 9, 3, 1을 사용하여 만드는 경우의 수 (permutation)
		{
			int nx = max(0, x - da[ i ][ 0 ]);
			int ny = max(0, y - da[ i ][ 1 ]);
			int nz = max(0, z - da[ i ][ 2 ]);
			if (vis[nx][ny][nz])
			{
				continue;
			}
			vis[ nx ][ ny ][ nz ] = vis[ x ][ y ][ z ] + 1;
			q.push({ nx, ny, nz });
		}
	}
	return vis[ 0 ][ 0 ][ 0 ];
}

int main()
{
	FastIO();

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[ i ];
	}

	op1l(BFS(a[ 0 ], a[ 1 ], a[ 2 ]) - 1);

	return 0;
}
