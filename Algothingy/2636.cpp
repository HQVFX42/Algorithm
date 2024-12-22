#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };
bool OOB(int x, int y, int n, int m) { return x < 0 or x >= n or y < 0 or y >= m; }
void FastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

const int MAX = 111;
int Graph[ MAX ][ MAX ];
int Visited[ MAX ][ MAX ];
int N, M, Cnt1, Cnt2;
vector<pii> V;

void Func(int y, int x)
{
	Visited[ y ][ x ] = 1;

	if (Graph[ y ][ x ] == 1)
	{
		V.push_back({ y, x });
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[ i ];
		int nx = x + dx[ i ];
		if (OOB(ny, nx, N, M) or Visited[ ny ][ nx ])
		{
			continue;
		}
		Func(ny, nx);
	}

	return;
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
		}
	}

	while (true)
	{
		fill(&Visited[ 0 ][ 0 ], &Visited[ 0 ][ 0 ] + MAX * MAX, 0);
		V.clear();

		Func(0, 0);
		Cnt2 = V.size();

		for (auto & i : V)
		{
			Graph[ i.first ][ i.second ] = 0;
		}

		bool bExist = false;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (Graph[ i ][ j ] != 0)
				{
					bExist = true;
				}
			}
		}

		Cnt1++;
		if (!bExist)
		{
			break;
		}
	}

	cout << Cnt1 << '\n' << Cnt2 << '\n';
}