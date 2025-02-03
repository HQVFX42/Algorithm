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

const int MAX = 333;
int n, m, vis[ MAX ][ MAX ];
string graph[ 333 ];
vector<pii> v;
int ans;

int main()
{
	ip2(n, m);

	int xx1, xy1, xx2, xy2;
	cin >> xx1 >> xy1 >> xx2 >> xy2;

	for (int i = 0; i < n; i++)
	{
		cin >> graph[ i ];
	}

	queue<pii> q;
	q.push({ xx1 - 1, xy1 - 1 });
	vis[ xx1 - 1 ][ xy1 - 1 ] = 1;
	while (graph[ xx2 - 1 ][ xy2 - 1 ] != '0')
	{
		ans++;
		queue<pii> tmp;
		while (!q.empty())
		{
			auto cur = q.front();
			q.pop();
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = cur.X + dx[ dir ];
				int ny = cur.Y + dy[ dir ];
				if (OOB(nx, ny, n, m) or vis[ nx ][ ny ])
				{
					continue;
				}
				if (graph[ nx ][ ny ] != '0')
				{
					graph[ nx ][ ny ] = '0';
					tmp.push({ nx, ny });
					vis[ nx ][ ny ] = vis[ cur.X ][ cur.Y ] + 1;
				}
				else
				{
					q.push({ nx, ny });
					vis[ nx ][ ny ] = vis[ cur.X ][ cur.Y ] + 1;
				}
			}
		}
		q = tmp;
	}

	op1(ans);
}
