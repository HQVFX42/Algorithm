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
		v.push_back(i < 7 ? 0 : 1);	// 25�� �� 7�� �ĺ� ����
	}
	do
	{
		queue<pair<int, int>> q;
		int cnt = 0, adj = 0;	// �ĺ��� �� �̴ټ����� ��, ������ ����� ��
		bool bP7[5][5] = {}, bVis[5][5] = {};
		for (int i = 0; i < 25; i++)
		{
			if (v[i] == 0)	// �ĺ��� ���õǾ��ٸ�
			{
				int x = i / 5;
				int y = i % 5;
				bP7[x][y] = true;	// ĥ���� ��ǥ ����
				if (q.empty())	// BFS ������ ����
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
					continue;	// OOB, 7���ְ� �ƴ� ���, �̹� �湮�� ���
				}
				q.push({ nx,ny });
				bVis[nx][ny] = true;
			}
		}
		ans += (adj >= 7 and cnt >= 4);	// ������ �ִ���, ������ ���ϰ� �ִ���
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