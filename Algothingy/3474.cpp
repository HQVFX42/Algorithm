#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
bool OOB(int x, int y, int n, int m) { return x < 0 or x >= n or y < 0 or y >= m; }
void FastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int main()
{
	FastIO();

	int TC = 0;
	cin >> TC;

	while (TC--)
	{
		int N = 0;
		cin >> N;

		int A2 = 0;
		int A5 = 0;
		for (int i = 2; i <= N; i *= 2)
		{
			A2 += N / i;
		}
		for (int j = 5; j <= N; j *= 5)
		{
			A5 += N / j;
		}

		cout << min(A2, A5) << '\n';
	}
}