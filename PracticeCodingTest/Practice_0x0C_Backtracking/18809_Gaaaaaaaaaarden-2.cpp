// 2s, 512MB
// 50 * 50
#include <bits/stdc++.h>
using namespace std;

int N, M, G, R, ans;
int graph[50][50];
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
vector<pair<int, int>> vStart;

void dfs2()
{
	// ������ �Ѹ� �� �ִ� �� �� ���� ���� ��ŭ ����
	// np[vStart.size()] : vStart = 10, g = 2, r = 4 : {0,0,0,0,1,1,2,2,2,2}
	int np[10];
	fill(np + vStart.size() - G - R, np + vStart.size() - R, 1);
	fill(np + vStart.size() - R, np + vStart.size(), 2);
	// 0 = emtpy, 1 = green, 2 = red, 3 = flower
	do
	{
		queue<pair<int, int>> q;
		int cnt = 0;
		pair<int, int> state[50][50];	// time, status
		for (int i = 0; i < vStart.size(); i++)
		{
			if (np[i] == 1 or np[i] == 2)	// ������ �Ѹ� �� �ִ� ���̸�
			{
				// ������ �Ѹ� �� �ִ� ���� ��ǥ�� status ����
				state[vStart[i].first][vStart[i].second] = { 0, np[i] };
				q.push(vStart[i]);	// bfs ���� ���� ����
			}
		}
		while (!q.empty())
		{
			int x, y;
			tie(x, y) = q.front(); q.pop();
			int curTime, curColour;
			tie(curTime, curColour) = state[x][y];
			if (curColour == 3) continue;	// ** ���� ������ �н� **
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = x + dx[dir], ny = y + dy[dir];
				if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;	// OOB �н�
				if (graph[nx][ny] == 0) continue;	// ȣ���� �н�
				if (state[nx][ny].second == 0)	// �� ��
				{
					state[nx][ny] = {curTime + 1, curColour};
					q.push({ nx, ny });
				}
				else if (state[nx][ny].second == 1)	// green
				{
					// �ݴ� �����̸鼭 ���� �ð��� ���ٸ�
					if (curColour == 2 && state[nx][ny].first == curTime + 1)
					{
						cnt++;
						state[nx][ny].second = 3;	// flower
					}
				}
				else if (state[nx][ny].second == 2)	// red
				{
					// �ݴ� �����̸鼭 ���� �ð��� ���ٸ�
					if (curColour == 1 && state[nx][ny].first == curTime + 1)
					{
						cnt++;
						state[nx][ny].second = 3;	// flower
					}
				}
			}
		}
		ans = max(ans, cnt);	// �ǿ� �� �ִ� ���� �ִ� ����
	} while (next_permutation(np, np + vStart.size()));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> G >> R;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> graph[i][j];
			if (graph[i][j] == 2)	// ������ �Ѹ� �� �ִ� �� �϶�
			{
				vStart.push_back({ i,j });	// Start������ ��ǥ�� ����
			}
		}
	}
	dfs2();
	cout << ans;
}