#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
bool OOB(int x, int y, int n, int m) { return x < 0 or x >= n or y < 0 or y >= m; }
void fastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

const int MAX = 11;
int graph[MAX][MAX];
int vis[MAX][MAX];

string split(string input, string delimiter)
{
	vector<string> ret;
	long long pos = 0;
	string token = "";
	while ((pos = input.find(delimiter)) != string::npos)
	{
		token = input.substr(0, pos);
		ret.push_back(token);
		input.erase(0, pos + delimiter.length());
	}
	ret.push_back(input);

	string output;
	for (auto& i : ret)
	{
		output += i;
	}
	return output;
}

struct Node
{
	int color; // 방의 색 (0: 흰색, 1: 빨간색, 2: 파란색)
	vector<int> adj; // 인접한 방의 번호
};

vector<Node> nodes;
int n, m;

int bfs(int start)
{
	queue<int> q;
	vector<bool> visited(n + 1, false);
	int Cnt = 0;
	q.push(start);
	visited[start] = true;
	nodes[start].color = 1;
	Cnt++;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int next : nodes[cur].adj)
		{
			if (!visited[next])
			{
				if (nodes[cur].color == 1)
				{
					nodes[next].color = 2;
				}
				else if (nodes[cur].color == 2)
				{
					nodes[next].color = 1;
					Cnt++;
				}

				q.push(next);
				visited[next] = true;
			}
		}
	}

	return Cnt;
}

void dfs(int y, int x)
{
	vis[y][x] = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (OOB(nx, ny, n, m))
		{
			continue;
		}
		if (graph[ny][nx] == 1 and vis[ny][nx] == 0)
		{
			dfs(ny, nx);
		}
	}
	return;
}

int main()
{
	fastIO();
	int sy, sx, ey, ex;
	cin >> n >> m;
	cin >> sy >> sx;
	cin >> ey >> ex;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
		}
	}

	queue<pii> q;
	vis[sy][sx] = 1;
	q.push({ sy, sx });

	int x = 0;
	int y = 0;
	while (!q.empty())
	{
		tie(y, x) = q.front();
		q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (OOB(ny, nx, n, m))
			{
				continue;
			}
			if (vis[ny][nx] != 0 or graph[ny][nx] != 1)
			{
				continue;
			}
			vis[ny][nx] = vis[y][x] + 1;
			q.push({ ny, nx });
		}
	}

	cout << vis[ey][ex];

	return 0;
}