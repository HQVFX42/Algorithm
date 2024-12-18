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

int N, M, Index;
string S, Result;
vector<string> V;

void Go()
{
	while (true)
	{
		if (Result.size() and Result.front() == '0')
		{
			Result.erase(Result.begin());
		}
		else
		{
			break;
		}
	}

	if (Result.size() == 0)
	{
		Result = "0";
	}
	V.push_back(Result);
	Result = "";
}

int main()
{
	cin >> N;
	while (N--)
	{
		cin >> S;
		Result = "";
		for (int i = 0; i < S.size(); i++)
		{
			if (S[i] < 'a')
			{
				Result += S[ i ];
			}
			else if(Result.size())
			{
				Go();
			}
		}
		if (Result.size())
		{
			Go();
		}
	}

	sort(V.begin(), V.end(),
		[ & ] (const string Lhs, const string Rhs)
		{
			if (Lhs.size() == Rhs.size())
			{
				return Lhs < Rhs;
			}
			return Lhs.size() < Rhs.size();
		});

	for (auto & i : V)
	{
		cout << i << "\n";
	}
}
