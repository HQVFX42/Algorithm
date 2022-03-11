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
	dist[n] = 0;
	q.push(n);
	//tp(n);	// 순간이동으로만 k에 도착할 수 있을 경우
	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		if (cur == k) break;
		for (auto& nxt : { cur - 1, cur + 1 })
		{
			if (nxt < 0 or nxt >= MX or dist[nxt] < dist[cur] + 1) continue;
			dist[nxt] = dist[cur] + 1;
			q.push(nxt);
			//tp(nxt);
		}
		if (2*cur < MX and dist[2*cur] > dist[cur])
		{
			dist[2 * cur] = dist[cur];
			q.push(2*cur);
		}
	}
}
void bfs2()
{	// 0-1BFS
	dist[n] = 0;
	deque<int> dq;
	dq.push_back(n);
	while (!dq.empty())
	{
		auto cur = dq.front(); dq.pop_front();
		for (auto& nxt : { cur - 1,cur + 1 })
		{
			if (nxt < 0 or nxt >= MX or dist[nxt] != -1) continue;
			dist[nxt] = dist[cur] + 1;
			dq.push_back(nxt);
		}
		if (2 * cur < MX and dist[2 * cur] == -1)
		{
			dist[2 * cur] = dist[cur];
			dq.push_front(2 * cur);
		}
	}
}

int main()
{
	fastIO();
	cin >> n >> k;
	fill(dist, dist + MX, 0x0f0f0f0f);
	bfs();
	//bfs2();
	cout << dist[k];
}

//#include<iostream>
//#include<queue>
//
//#define endl "\n"
//#define MAX 100000 + 1
//#define INF 0x0f0f0f0f
//using namespace std;
//
//int N, K;
//int Visit[MAX];
//
//void Input()
//{
//    cin >> N >> K;
//    for (int i = 0; i < MAX; i++)
//    {
//        Visit[i] = INF;
//    }
//}
//
//int BFS()
//{
//    queue<int> Q;
//    Q.push(N);
//    Visit[N] = 0;
//
//    while (Q.empty() == 0)
//    {
//        int Pos = Q.front();
//        Q.pop();
//
//        if (Pos == K) return Visit[K];
//
//        if (Pos * 2 < MAX && Visit[Pos * 2] > Visit[Pos])
//        {
//            cout << Visit[Pos * 2] << ' ' << Visit[Pos] << endl;
//            Visit[Pos * 2] = Visit[Pos];
//            Q.push(Pos * 2);
//        }
//        if (Pos + 1 < MAX && Visit[Pos + 1] > Visit[Pos] + 1)
//        {
//            cout << Visit[Pos+1] << ' ' << Visit[Pos] + 1 << endl;
//            Visit[Pos + 1] = Visit[Pos] + 1;
//            Q.push(Pos + 1);
//        }
//
//        if (Pos - 1 >= 0 && Visit[Pos - 1] > Visit[Pos] + 1)
//        {
//            Visit[Pos - 1] = Visit[Pos] + 1;
//            Q.push(Pos - 1);
//            cout << -1 << endl;
//        }
//
//    }
//}
//
//void Solution()
//{
//    int R = BFS();
//    cout << R << endl;
//}
//
//void Solve()
//{
//    Input();
//    Solution();
//}
//
//int main(void)
//{
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//
//    Solve();
//
//    return 0;
//}