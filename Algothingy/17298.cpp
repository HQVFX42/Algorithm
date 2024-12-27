#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };
bool OOB(int x, int y, int n, int m) { return x < 0 or x >= n or y < 0 or y >= m; }
void FastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

const int MAX = 1111111;
stack<int> Sta;
int N, A[ MAX ], R[ MAX ];

int main()
{
	FastIO();
	
	memset(R, -1, sizeof(R));

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[ i ];
		while (Sta.size() and A[Sta.top()] < A[i])
		{
			R[ Sta.top() ] = A[ i ];
			Sta.pop();
		}
		Sta.push(i);
	}

	for (int i = 0; i < N; i++)
	{
		cout << R[ i ] << " ";
	}
}
