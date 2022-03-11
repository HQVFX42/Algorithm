#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
bool OOB(int x, int y, int n, int m) { return x < 0 or x >= n or y < 0 or y >= m; }
void fastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

const int MX = 222222;
int n, k;
int dist[MX];
queue<int> q;

void tp(int nxt)
{	// 순간이동을 하는 경우	
	int tmp = nxt;
	if (tmp == 0) { return; }
	while (tmp < MX and dist[k] == -1)
	{	// 범위 안에 들어오고 k에 방문하지 않았을 때
		if (dist[tmp] == -1)
		{
			dist[tmp] = dist[nxt];
			q.push(tmp);
			if (tmp == k) return;
		}
		tmp = tmp << 1;
	}
}
void bfs()
{
	fill(dist, dist + MX, -1);
	dist[n] = 0;	
	q.push(n);
	tp(n);	// 순간이동으로만 k에 도착할 수 있을 경우
	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (auto& nxt : { cur - 1, cur + 1 })
		{
			if (nxt < 0 or nxt >= MX or dist[nxt] != -1) continue;
			dist[nxt] = dist[cur] + 1;
			q.push(nxt);
			tp(nxt);
		}
	}
}
void bfs2()
{	// 0-1BFS
	
}

int main()
{
	fastIO();
	cin >> n >> k;
	//bfs();
	bfs2();
	cout << dist[k];
}