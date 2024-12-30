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
#define op2l(a) cout << a << ' ' << b << '\n'

const int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };

bool OOB(int x, int y, int n, int m) { return x < 0 or x >= n or y < 0 or y >= m; }
void FastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

const int MAX = 55;
int n, m, graph[ MAX ][ MAX ], answer = 987654321;
vector<pii> vH, vC;
vector<vector<int>> vCLists;

void Combi(int start, vector<int> v)
{
	if (v.size() == m)
	{
		vCLists.push_back(v);
		return;
	}

	for (int i = start + 1; i < vC.size(); i++)
	{
		v.push_back(i);
		Combi(i, v);
		v.pop_back();
	}

	return;
}

int main()
{
	FastIO();

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> graph[ i ][ j ];
			if (graph[ i ][ j ] == 1)
			{
				vH.push_back({ i, j });
			}
			if (graph[ i ][ j ] == 2)
			{
				vC.push_back({ i, j });
			}
		}
	}

	vector<int> v;
	Combi(-1, v);

	for (auto & CList : vCLists)
	{
		int ans = 0;
		for (auto & Home : vH)
		{
			int mn = 987654321;
			for (auto & Ch : CList)
			{
				int dist = abs(Home.first - vC[ Ch ].first) + abs(Home.second - vC[ Ch ].second);
				mn = min(mn, dist);
			}
			ans += mn;
		}
		answer = min(answer, ans);
	}

	op1l(answer);
}
