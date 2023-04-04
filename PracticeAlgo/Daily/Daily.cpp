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
	int C;
	cin >> N >> C;

	vector<pii> v;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		bool flag = false;
		for (auto& j : v)
		{
			if (j.first == tmp)
			{
				flag = true;
				j.second++;
				break;
			}
		}
		if (!flag)
		{
			v.push_back({ tmp, 1 });
		}
	}

	stable_sort(v.begin(), v.end(),
		[&](const pii lhs, const pii rhs)
		{
			return lhs.second > rhs.second;
		});

	for (auto& i : v)
	{
		while (i.second--)
		{
			cout << i.first << ' ';
		}
	}

	return 0;
}