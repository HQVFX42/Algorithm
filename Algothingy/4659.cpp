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

bool IsVowel(int index)
{
	return (index == 'a' or index == 'e' or index == 'i' or index == 'o' or index == 'u');
}

int main()
{
	fastIO();

	while (true)
	{
		string s;
		cin >> s;
		if (s == "end")
		{
			break;
		}

		int Lcnt = 0;
		int Rcnt = 0;
		bool bFlag = false;
		bool bVowelIncluded = false;
		int prev = -1;
		for (int i = 0; i < s.size(); i++)
		{
			int TC = s[ i ];
			if (IsVowel(TC))
			{
				Lcnt++;
				Rcnt = 0;
				bVowelIncluded = true;
			}
			else
			{
				Rcnt++;
				Lcnt = 0;
			}

			if (Rcnt == 3 or Lcnt == 3)
			{
				bFlag = true;
			}

			if (i >= 1 and prev == TC and TC != 'e' and TC != 'o')
			{
				bFlag = true;
			}

			prev = TC;
		}

		if (!bVowelIncluded)
		{
			bFlag = true;
		}
		if (bFlag)
		{
			cout << "<" << s << ">" << " is not acceptable.\n";
		}
		else
		{
			cout << "<" << s << ">" << " is acceptable.\n";
		}
	}
}
