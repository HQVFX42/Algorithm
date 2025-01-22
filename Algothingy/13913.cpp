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

const int MAX = 111111;
int n, k, vis[ MAX ], trace[ MAX ];
vector<int> ans;

int main()
{
	FastIO();

	ip2(n, k);

	vis[ n ] = 1;

	queue<int> q;
	q.push(n);
	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();
		for (int nxt : {cur - 1, cur + 1, cur * 2})
		{
			if (nxt < 0 or nxt >= MAX or vis[ nxt ])
			{
				continue;
			}

			vis[ nxt ] = vis[ cur ] + 1;
			trace[ nxt ] = cur;
			q.push(nxt);
		}
	}

	for (int i = k; i != n; i = trace[i])
	{
		ans.push_back(i);
	}
	ans.push_back(n);
	reverse(ans.begin(), ans.end());

	op1l(vis[ k ] - 1);
	for (auto & i : ans)
	{
		op1(i);
	}
}
