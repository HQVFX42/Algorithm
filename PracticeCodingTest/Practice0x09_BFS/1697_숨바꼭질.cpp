#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dist[10002];
int n, k;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	fill(dist, dist + 10001, -1);
	dist[n] = 0;
	queue<int> q;
	q.push(n);
	while (dist[k] == -1)
	{
		int cur = q.front();
		q.pop();
		for (int nxt : {cur - 1, cur + 1, 2 * cur})
		{
			if (nxt < 0 || nxt > 10000) continue;
			if (dist[nxt] != -1) continue;
			dist[nxt] = dist[cur] + 1;
			q.push(nxt);
		}
	}
	cout << dist[k];
}