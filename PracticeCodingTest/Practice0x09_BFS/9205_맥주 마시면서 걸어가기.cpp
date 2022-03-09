#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
bool OOB(int x, int y, int n, int m) { return x < 0 or x >= n or y < 0 or y >= m; }

#define X first
#define Y second
#define rep(i,a,b) for(int i = a; i < b; i++)
#define ip1(a) cin >> a
#define ip2(a,b) cin >> a >> b
#define op1(a) cout << a << ' '
#define op2(a,b) cout << a << ' ' << b
#define op1l(a) cout << a << '\n'
#define op2l(a) cout << a << ' ' << b << '\n'
#define opl cout << '\n'
// Manhattan-Metric
int dist(pii a, pii b)
{
	return abs(a.X - b.X) + abs(a.Y - b.Y);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int TC;
	ip1(TC);
	rep(i, 0, TC)
	{
		bool ans = false;
		int n;
		ip1(n);

		pii start, end, store[111];
		ip2(start.X, start.Y);
		rep(i, 0, n) ip2(store[i].X, store[i].Y);
		ip2(end.X, end.Y);

		int vis[111] = {};
		queue<int> q;

		if (dist(start, end) <= 1000)
		{
			op1l("happy");
			continue;
		}

		rep(i, 0, n)
		{
			if (dist(start, store[i]) <= 1000)
			{
				q.push(i);
				vis[i] = 1;
			}
		}

		while (!q.empty())
		{
			auto cur = q.front();
			q.pop();
			if (dist(store[cur], end) <= 1000)
			{
				ans = true;
				break;
			}
			rep(i, 0, n)
			{
				if (vis[i] == 0 and dist(store[i], store[cur]) <= 1000)
				{
					q.push(i);
					vis[i] = 1;
				}
			}
		}

		if (!ans) op1l("sad");
		else op1l("happy");
	}
}