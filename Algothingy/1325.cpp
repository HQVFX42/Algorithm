#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };
bool OOB(int x, int y, int n, int m) { return x < 0 or x >= n or y < 0 or y >= m; }
void FastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

const int MAX = 11111;
int N, M, A, B, Vis[ MAX ], dp[ MAX ], mx;
vector<int> Adj[ MAX ];

int dfs(int here)
{
	int Result = 1;
	Vis[ here ] = 1;
	for (int there : Adj[ here ])
	{
		if (Vis[ there ])
		{
			continue;
		}
		Result += dfs(there);
	}

	return Result;
}

int main()
{
	FastIO();

	cin >> N >> M;
	while (M--)
	{
		cin >> A >> B;
		Adj[ B ].push_back(A);
	}

	for (int i = 1; i <= N; i++)
	{
		memset(Vis, 0, sizeof(Vis));
		dp[ i ] = dfs(i);
		mx = max(dp[ i ], mx);
	}

	for (int i = 1; i <= N; i++)
	{
		if (mx == dp[ i ])
		{
			cout << i << " ";
		}
	}

	return 0;
}