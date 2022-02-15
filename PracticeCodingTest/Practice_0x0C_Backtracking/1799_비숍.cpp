// 10s, 128MB
// 10 * 10
#include <bits/stdc++.h>
using namespace std;

int n, ans[2], bUsed[2][20];
vector<pair<int, int>> vStart[2][20];	// [흑,백][\방향 대각선에 포함된 칸]

void dfs(int depth, int cnt, int colour)
{
	if (depth == 2 * n)
	{
		ans[colour] = max(ans[colour], cnt);
		return;
	}
	for (auto& i : vStart[colour][depth])
	{
		int x, y;
		tie(x, y) = i;
		if (bUsed[colour][x + y]) continue;
		bUsed[colour][x + y] = true;
		dfs(depth + 1, cnt + 1, colour);
		bUsed[colour][x + y] = false;
	}
	dfs(depth + 1, cnt, colour);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int graph;
			cin >> graph;
			if (graph) vStart[(i + j + 1) % 2][i - j + n - 1].push_back({ i,j });
		}
	}
	dfs(0, 0, 0);
	dfs(0, 0, 1);
	cout << ans[0] + ans[1];
}