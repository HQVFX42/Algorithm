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

int n, l, r;
int vis[ 55 ][ 55 ], graph[ 55 ][ 55 ];
int cnt, sum;
vector<pii> v;

void dfs(int y, int x)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[ i ];
		int nx = x + dx[ i ];

		if (OOB(ny, nx, n, n) or vis[ ny ][ nx ])
		{
			continue;
		}
		if (l <= abs(graph[ ny ][ nx ] - graph[ y ][ x ]) and abs(graph[ ny ][ nx ] - graph[ y ][ x ]) <= r)
		{
			vis[ ny ][ nx ] = 1;
			v.push_back({ ny, nx });
			sum += graph[ ny ][ nx ];
			dfs(ny, nx);
		}
	}
}

int main()
{
	FastIO();

	cin >> n >> l >> r;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> graph[ i ][ j ];
		}
	}

	while (true)
	{
		bool bFlag = 0;
		fill(&vis[ 0 ][ 0 ], &vis[ 0 ][ 0 ] + 55 * 55, 0);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (!vis[ i ][ j ])
				{
					v.clear();
					vis[ i ][ j ] = 1;
					v.push_back({ i, j });
					sum = graph[ i ][ j ];
					dfs(i, j);
					if (v.size() == 1)
					{
						continue;
					}
					for (pii vv : v)
					{
						graph[ vv.first ][ vv.second ] = sum / v.size();
						bFlag = true;
					}
				}
			}
		}

		if (!bFlag)
		{
			break;
		}
		cnt++;
	}

	cout << cnt;
}
