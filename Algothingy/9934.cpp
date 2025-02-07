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

const int MX = 1111;	// 2^10 = 1024
int k, tree[MX];
vector<int> ans[ 11 ];

void Func(int s, int e, int level)
{
	if (s > e)
	{
		return;
	}
	if (s == e)
	{
		ans[ level ].push_back(tree[ s ]);
		return;
	}

	int mid = (s + e) / 2;
	ans[ level ].push_back(tree[ mid ]);
	Func(s, mid - 1, level + 1);
	Func(mid + 1, e, level + 1);
	return;
}

int main()
{
	FastIO();

	cin >> k;
	int node = ( int ) pow(2, k) - 1;
	for (int i = 0; i < node; i++)
	{
		cin >> tree[ i ];
	}

	Func(0, node, 1);

	for (int i = 1; i <= k; i++)
	{
		for (int j : ans[ i ])
		{
			op1(j);
		}
		opl;
	}
}
