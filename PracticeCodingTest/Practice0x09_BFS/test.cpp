#include <bits/stdc++.h>
using namespace std;

int dist[100002], n, k;

int main()
{
	cin >> n >> k;
	fill(dist, dist+100001, -1);
	dist[n] = 0;
	queue<int> q;
	q.push(n);

	while (dist[k] == -1)
	{
		int cur = q.front(); q.pop();
		for (int nx : {cur - 1, cur + 1, 2 * cur})
		{
			if (nx < 0 || nx > 100000)
			{
				continue;
			}
			if (dist[nx] != -1)
			{
				continue;
			}
			dist[nx] = dist[cur] + 1;
			q.push(nx);
		}
	}
	cout << dist[k];
}