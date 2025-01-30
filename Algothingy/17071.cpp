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

const int MAX = 500000;
int n, k, vis[ 2 ][ MAX + 4 ], turn = 1;
bool ok;

int main()
{
	ip2(n, k);

	if (n == k)
	{
		op1l(0);
		return 0;
	}

	queue<int> q;
	q.push(n);
	vis[ 0 ][ n ] = 1;
	while (!q.empty())
	{
		k += turn;
		if (k > MAX)
		{
			break;
		}

		if (vis[ turn & 1 ][ k ])
		{
			ok = true;
			break;
		}

		int qSize = q.size();
		for (int i = 0; i < qSize; i++)
		{
			int x = q.front();
			q.pop();
			for (int nxt : {x - 1, x + 1, x * 2})
			{
				if (nxt < 0 or nxt > MAX or vis[ turn & 1 ][ nxt ])
				{
					continue;
				}
				vis[ turn % 2 ][ nxt ] = vis[ (turn + 1) & 1 ][ x ] + 1;
				if (nxt == k)
				{
					ok = true;
					break;
				}
				q.push(nxt);
			}
			if (ok)
			{
				break;
			}
		}
		if (ok)
		{
			break;
		}
		turn++;
	}

	if (ok)
	{
		op1l(turn);
	}
	else
	{
		op1l(-1);
	}

	return 0;
}
