#include <bits/stdc++.h>
using namespace std;

int dist[1000002];
int F, S, G, U, D;
queue<int> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> F >> S >> G >> U >> D;
	fill(dist, dist + F + 1, -1);
	dist[S] = 0;
	q.push(S);

	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 2; dir++)
		{
			int nx;
			if (dir == 0) nx = cur + U;
			else nx = cur - D;
			if (nx <= 0 || nx > F || dist[nx] != -1) continue;
			dist[nx] = dist[cur] + 1;
			q.push(nx);
		}
		// 위의 for문과 똑같은 동작을 하는 ranged for문
		//for (auto nxt : { cur + U,cur - D })
		//{
		//	if (nxt <= 0 || nxt > F || dist[nxt] != -1) continue;
		//	dist[nxt] = dist[cur] + 1;
		//	q.push(nxt);
		//}
	}
	if (dist[G] == -1) cout << "use the stairs";
	else cout << dist[G];
}