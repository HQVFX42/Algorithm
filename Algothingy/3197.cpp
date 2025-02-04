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

const int MAX = 1555;
int r, c, vis1[ MAX ][ MAX ], vis2[ MAX ][ MAX ];
string graph[ MAX ];
int stX, stY;
queue<pii> q1;
queue<pii> q1tmp;
queue<pii> q2;
queue<pii> q2tmp;

bool Swan()
{
	while (!q2.empty())
	{
		int x, y;
		tie(x, y) = q2.front();
		q2.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = x + dx[ dir ];
			int ny = y + dy[ dir ];
			if (OOB(nx, ny, r, c) or vis2[ nx ][ ny ])
			{
				continue;
			}

			vis2[ nx ][ ny ] = 1;
			if (graph[ nx ][ ny ] == '.')
			{
				q2.push({ nx, ny });
			}
			else if (graph[ nx ][ ny ] == 'X')
			{
				q2tmp.push({ nx, ny });
			}
			else if (graph[ nx ][ ny ] == 'L')
			{
				return true;
			}
		}
	}
	return false;
}

void Melt()
{
	while (!q1.empty())
	{
		auto cur = q1.front();
		q1.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[ dir ];
			int ny = cur.Y + dy[ dir ];
			if (OOB(nx, ny, r, c) or vis1[ nx ][ ny ])
			{
				continue;
			}

			if (graph[ nx ][ ny ] == 'X')
			{
				vis1[ nx ][ ny ] = 1;
				q1tmp.push({ nx, ny });
				graph[ nx ][ ny ] = '.';
			}
		}
	}
}

void ClearQueue(queue<pii> & q)
{
	queue<pii> tmp;
	swap(q, tmp);
}

int main()
{
	FastIO();

	ip2(r, c);

	for (int i = 0; i < r; i++)
	{
		cin >> graph[ i ];
		for (int j = 0; j < c; j++)
		{
			if (graph[ i ][ j ] == 'L')
			{

				stX = i;
				stY = j;
			}
			if (graph[ i ][ j ] == '.' or graph[ i ][ j ] == 'L')
			{
				vis1[ i ][ j ] = 1;
				q1.push({ i, j });
			}
		}
	}

	int ans = 0;
	q2.push({ stX, stY });
	vis2[ stX ][ stY ] = 1;
	while (true)
	{
		if (Swan())
		{
			break;
		}
		Melt();
		q1 = q1tmp;
		q2 = q2tmp;
		ClearQueue(q1tmp);
		ClearQueue(q2tmp);
		ans++;
	}

	op1(ans);
}
