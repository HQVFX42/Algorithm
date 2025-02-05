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

const int MX = 22;
int r, c, vis[ 33 ], ans;
string graph[ MX ];

void DFS(int x, int y, int cnt)
{
	ans = max(ans, cnt);
	for (int dir = 0; dir < 4; dir++)
	{
		int nx = x + dx[ dir ];
		int ny = y + dy[ dir ];
		if (OOB(nx, ny, r, c))
		{
			continue;
		}

		int nxt = ( int ) (graph[ nx ][ ny ] - 'A');
		if (vis[ nxt ] == 0)
		{
			vis[ nxt ] = 1;
			DFS(nx, ny, cnt + 1);
			vis[ nxt ] = 0;
		}
	}
}

int main()
{
	FastIO();

	ip2(r, c);

	for (int i = 0; i < r; i++)
	{
		cin >> graph[ i ];
	}

	vis[ ( int ) (graph[ 0 ][ 0 ] - 'A') ] = 1;

	DFS(0, 0, 1);

	op1l(ans);
}
