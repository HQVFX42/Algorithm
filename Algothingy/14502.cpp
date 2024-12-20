#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };
bool OOB(int x, int y, int n, int m) { return x < 0 or x >= n or y < 0 or y >= m; }
void FastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

const int MAX = 11;
int Graph[ MAX ][ MAX ];
bool Visited[ MAX ][ MAX ];
vector<pii> Virus;
vector<pii> Wall;
int N, M, Result;

void DFS(int Y, int X)
{
	for (int i = 0; i < 4; i++)
	{
		int NY = Y + dy[ i ];
		int NX = X + dx[ i ];
		if (OOB(NY, NX, N, M) or Visited[ NY ][ NX ] or Graph[ NY ][ NX ] == 1)
		{
			continue;
		}
		Visited[ NY ][ NX ] = true;
		DFS(NY, NX);
	}

	return;
}

int Solve()
{
	fill(&Visited[ 0 ][ 0 ], &Visited[ 0 ][ 0 ] + MAX * MAX, false);
	for (auto & i : Virus)
	{
		Visited[ i.first ][ i.second ] = true;
		DFS(i.first, i.second);
	}

	int Cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (Graph[ i ][ j ] == 0 and !Visited[ i ][ j ])
			{
				Cnt++;
			}
		}
	}
	return Cnt;
}

int main()
{
	FastIO();

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> Graph[ i ][ j ];
			if (Graph[ i ][ j ] == 2)
			{
				Virus.push_back({ i, j });
			}
			if (Graph[ i ][ j ] == 0)
			{
				Wall.push_back({ i, j });
			}
		}
	}

	for (int i = 0; i < Wall.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			for (int k = 0; k < j; k++)
			{
				Graph[ Wall[ i ].first ][ Wall[ i ].second ] = 1;
				Graph[ Wall[ j ].first ][ Wall[ j ].second ] = 1;
				Graph[ Wall[ k ].first ][ Wall[ k ].second ] = 1;
				Result = max(Result, Solve());
				Graph[ Wall[ i ].first ][ Wall[ i ].second ] = 0;
				Graph[ Wall[ j ].first ][ Wall[ j ].second ] = 0;
				Graph[ Wall[ k ].first ][ Wall[ k ].second ] = 0;
			}
		}
	}

	cout << Result;
}