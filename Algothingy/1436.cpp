#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
bool OOB(int x, int y, int n, int m) { return x < 0 or x >= n or y < 0 or y >= m; }
void FastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int main()
{
	FastIO();

	int N = 0;
	cin >> N;

	int i = 666;
	for (;; i++)
	{
		if (to_string(i).find("666") != string::npos)
		{
			N--;
		}
		if (N == 0)
		{
			break;
		}
	}

	cout << i << '\n';
}