#include <bits/stdc++.h>
using namespace std;

string graph[5];
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
int ans;

void dfs2()
{
	vector<int> v;
	for (int i = 0; i < 25; i++)
	{
		v.push_back(i < 7 ? 0 : 1);	// 25명 중 7명 후보 선택
	}
	do
	{
		queue<pair<int, int>> q;
		int cnt = 0, adj = 0;	// 후보들 중 이다솜파의 수, 인접한 사람의 수
		bool bP7[5][5] = {}, bVis[5][5] = {};
		for (int i = 0; i < 25; i++)
		{
			if (v[i] == 0)	// 후보로 선택되었다면
			{
				int x = i / 5;
				int y = i % 5;
				bP7[x][y] = true;	// 칠공주 좌표 대입
				if (q.empty())	// BFS 시작점 설정
				{
					q.push({ x,y });
					bVis[x][y] = true;
				}
			}
		}
		while (!q.empty())
		{
			int x, y;
			tie(x, y) = q.front();
			q.pop();
			adj++;
			cnt += graph[x][y] == 'S';
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = x + dx[dir], ny = y + dy[dir];
				if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || !bP7[nx][ny] || bVis[nx][ny])
				{
					continue;	// OOB, 7공주가 아닐 경우, 이미 방문한 경우
				}
				q.push({ nx,ny });
				bVis[nx][ny] = true;
			}
		}
		ans += (adj >= 7 and cnt >= 4);	// 인접해 있는지, 우위를 점하고 있는지
	} while (next_permutation(v.begin(), v.end()));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 5; i++)
	{
		cin >> graph[i];
	}
	dfs2();
	cout << ans;
}