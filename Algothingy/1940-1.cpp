#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

#define opl cout << '\n'
#define op1(a) cout << a << ' '

const int dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };
bool OOB(int x, int y, int n, int m) { return x < 0 or x >= n or y < 0 or y >= m; }
void FastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int n, m, a[ 15555 ], cnt;

void Combi(int idx, vector<int> & v)
{
	if (v.size() == 2)
	{
		int b = a[ v[ 0 ] ];
		int c = a[ v[ 1 ] ];
		if (b + c == m)
		{
			cnt++;
		}

		return;
	}

	for (int i = idx + 1; i < n; i++)
	{
		v.push_back(i);
		Combi(i, v);
		v.pop_back();
	}
}

int main()
{
	FastIO();

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[ i ];
	}

	vector<int> v;
	Combi(-1, v);

	op1(cnt);
}