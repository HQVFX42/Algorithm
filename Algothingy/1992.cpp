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

string a[64];

string Quard(int y, int x, int size)
{
	if (size == 1)
	{
		return string(1, a[y][x]);
	}

	string ans = "";
	for (int i = y; i < y + size; i++)
	{
		for (int j = x; j < x + size; j++)
		{
			if (a[y][x] != a[i][j])
			{
				ans += '(';
				ans += Quard(y, x, size * .5);
				ans += Quard(y, x + size * .5, size * .5);
				ans += Quard(y + size * .5, x, size * .5);
				ans += Quard(y + size * .5, x + size * .5, size * .5);
				ans += ')';

				return ans;
			}
		}
	}

	return string(1, a[y][x]);
}

int main()
{
	fastIO();

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	cout << Quard(0, 0, n) << '\n';
}