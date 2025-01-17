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

int n, ans = -987654321;
string s;
vector<int> numV;
vector<char> opV;

int Op(char a, int b, int c)
{
	if (a == '+')
	{
		return b + c;
	}
	if (a == '-')
	{
		return b - c;
	}
	if (a == '*')
	{
		return b * c;
	}
}

void Recursive(int here, int there)
{
	if (here == numV.size() - 1)
	{
		ans = max(ans, there);
		return;
	}

	Recursive(here + 1, Op(opV[ here ], there, numV[ here + 1 ]));
	if (here + 2 <= numV.size() - 1)
	{
		int tmp = Op(opV[ here + 1 ], numV[ here + 1 ], numV[ here + 2 ]);
		Recursive(here + 2, Op(opV[ here ], there, tmp));
	}

	return;
}

int main()
{
	FastIO();
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++)
	{
		if ((i & 1) == 0)
		{
			numV.push_back(s[ i ] - '0');
		}
		else
		{
			opV.push_back(s[ i ]);
		}
	}

	Recursive(0, numV[ 0 ]);

	op1l(ans);

	return 0;
}
