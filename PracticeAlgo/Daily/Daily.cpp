#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef pair<int, int> pii;

const int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
bool OOB(int x, int y, int n, int m) { return x < 0 or x >= n or y < 0 or y >= m; }
void fastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

const int MAX = 1111;
int graph[MAX][MAX];
int vis[MAX][MAX];
string a[MAX];

int main()
{
	int N;
	int M;
	int J;
	cin >> N >> M >> J;
	int l = 1;

	int res = 0;
	while (J--)
	{
		int r = l + M - 1;
		int temp;
		cin >> temp;
		if (temp >= l and temp <= r)
		{
			continue;
		}
		if (temp < l)
		{
			res += l - temp;
			l = temp;
		}
		else
		{
			res += temp - r;
			l += temp - r;
		}
	}

	cout << res;

	return 0;
}