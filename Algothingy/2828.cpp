#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ldb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

static bool OOB(int x, int y, int n, int m) { return x < 0 or x >= n or y < 0 or y >= m; }

void fastIO()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
}

int n, m, j;

int main()
{
	fastIO();

	cin >> n >> m >> j;

	int ans = 0;
	int l = 1;
	for (int i = 0; i < j; i++)
	{
		int r = l + m - 1;
		
		int tmp;
		cin >> tmp;

		if (tmp >= l and tmp <= r)
		{
			continue;
		}
		else
		{
			if (r < tmp)
			{
				ans += tmp - r;
				l += tmp - r;
			}
			else
			{
				ans += l - tmp;
				l = tmp;
			}
		}
	}

	cout << ans << '\n';
}