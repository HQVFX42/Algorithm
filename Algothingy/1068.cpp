#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };
bool OOB(int x, int y, int n, int m) { return x < 0 or x >= n or y < 0 or y >= m; }
void FastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int N, R, Temp, Root;
vector<int> Adj[ 55 ];

int DFS(int here)
{
	int Result = 0;
	int Child = 0;

	for (auto& there : Adj[ here ])
	{
		if (there == R)
		{
			continue;
		}
		Result += DFS(there);
		Child++;
	}

	if (Child == 0)
	{
		return 1;
	}

	return Result;
}

int main()
{
	FastIO();

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> Temp;
		if (Temp == -1)
		{
			Root = i;
		}
		else
		{
			Adj[ Temp ].push_back(i);
		}
	}

	cin >> R;
	if (R == Root)
	{
		cout << 0 << '\n';
	}
	else
	{
		cout << DFS(Root) << '\n';
	}
}