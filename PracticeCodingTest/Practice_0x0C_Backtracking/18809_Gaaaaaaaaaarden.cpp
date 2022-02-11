// 2s, 512MB
// 50 * 50
#include <bits/stdc++.h>
using namespace std;

int graph[50][50];
int vis[50][50];
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
int N, M, G, R;
int ans;
vector<pair<int, int>> canStart;
vector<int> vG, vR;

bool bUsed[10];

void input()
{
	cin >> N >> M >> G >> R;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> graph[i][j];
			if (graph[i][j] == 2)
			{
				canStart.push_back({ i,j });
			}
		}
	}
}

int bfs()
{
	int cnt = 0;
	pair<int, int> state[50][50];	// time, colour
	queue<pair<int, int>> q;
	for (auto& i : vG)
	{
		int x = canStart[i].first;
		int y = canStart[i].second;
		state[x][y] = { 0,0 };
		q.push({ x,y });
	}
	for (auto& i : vR)
	{
		int x = canStart[i].first;
		int y = canStart[i].second;
		state[x][y] = { 0,1 };
		q.push({ x,y });
	}
	while (!q.empty())
	{
		int x, y;
		tie(x, y) = q.front();
		int time = state[x][y].first;
		int colour = state[x][y].second;
		q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = x + dx[dir], ny = y + dy[dir];
			if (nx < 0 or nx >= N or ny < 0 or ny >= M or graph[nx][ny] == 0)
			{
				continue;
			}
			if (state[nx][ny].second == -1)
			{

			}
		}

	}
	return 0;
}

void dfs(int depth, int start, int green, int red)
{
	if (depth > canStart.size() or green > G or red > R) return;
	if (green == G && red == R) ans = max(ans, bfs());
	for (int i = start; i < canStart.size(); i++)
	{
		if (bUsed[i] == true) continue;
		bUsed[i] = true;
		vG.push_back(i);
		dfs(depth + 1, i, green + 1, red);
		vG.pop_back();
		vR.push_back(i);
		dfs(depth + 1, i, green, red + 1);
		vR.pop_back();
		bUsed[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	input();
	dfs(0, 0, 0, 0);
	cout << ans;
}