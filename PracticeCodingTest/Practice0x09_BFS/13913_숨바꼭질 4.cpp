#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
bool OOB(int x, int y, int n, int m) { return x < 0 or x >= n or y < 0 or y >= m; }
void fastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

const int MX = 111111;
int n, k;
int dist[MX], pre[MX];

int main()
{
	fastIO();
	cin >> n >> k;
	fill(dist, dist + MX, -1);
	dist[n] = 0;
	queue<int> q;
	q.push(n);

	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (auto& nxt : { cur - 1, cur + 1, 2 * cur })
		{
			if (nxt < 0 or nxt >= MX or dist[nxt] != -1) continue;
			dist[nxt] = dist[cur] + 1;
			q.push(nxt);
			pre[nxt] = cur;
		}
	}
	cout << dist[k] << '\n';
	deque<int> qPre = { k };
	while (qPre.front() != n)
	{
		qPre.push_front(pre[qPre.front()]);
	}
	for (auto& i : qPre)
	{
		cout << i << ' ';
	}
}