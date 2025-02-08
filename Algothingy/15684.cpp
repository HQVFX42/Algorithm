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

int n, m, h, a, b, vis[ 33 ][ 33 ], ans = 4;

bool Check()	// i번째가 i번째로 오는지 확인
{
	for (int i = 1; i <= n; i++)
	{
		int st = i;
		for (int j = 1; j <= h; j++)
		{
			if (vis[ j ][ st ])
			{
				st++;
			}
			else if (vis[ j ][ st - 1 ])
			{
				st--;
			}
		}
		if (st != i)
		{
			return false;
		}
	}
	return true;
}

void Func(int here, int cnt)
{
	if (cnt > 3 or cnt >= ans)
	{
		return;
	}
	if (Check())
	{
		ans = min(ans, cnt);
		return;
	}
	for (int i = here; i <= h; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (vis[ i ][ j ] or vis[ i ][ j - 1 ] or vis[ i ][ j + 1 ])
			{
				continue;
			}
			vis[ i ][ j ] = 1;
			Func(i, cnt + 1);
			vis[ i ][ j ] = 0;
		}
	}
}

int main()
{
	FastIO();

	cin >> n >> m >> h;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		vis[ a ][ b ] = 1;
	}
	Func(1, 0);

	op1(((ans > 3) ? -1 : ans));
}
