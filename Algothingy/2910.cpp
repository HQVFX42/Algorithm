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

int N, C;
int a[ 1111 ];
map<int, int> M, M_First;
vector<pii> v;

void fastIO()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
}

int main()
{
	fastIO();
		
	cin >> N >> C;

	for (int i = 0; i < N; i++)
	{
		cin >> a[ i ];
		M[ a[ i ] ]++;
		if (M_First[ a[ i ] ] == 0)
		{
			M_First[ a[ i ] ] = i + 1;
		}
	}
	
	for (auto & iterator : M)
	{
		v.push_back({ iterator.second, iterator.first });
	}

	sort(v.begin(), v.end(),
		[ & ] (const pii lhs, const pii rhs)
		{
			if (lhs.first == rhs.first)
			{
				return M_First[ lhs.second ] < M_First[ rhs.second ];
			}
			return lhs.first > rhs.first;
		});

	for (auto & i : v)
	{
		while (i.first--)
		{
			cout << i.second << ' ';
		}
	}
}