#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[502][502];
bool hasVisited[502][502];
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}
	int max = 0;
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 0 || hasVisited[i][j])
			{
				continue;
			}
			num++;
			queue < pair<int, int> > q;
			hasVisited[i][j] = 1;
			q.push({ i,j });
			int area = 0;
			while (!q.empty())
			{
				area++;
				auto cur = q.front();
				q.pop();
				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
					{
						continue;
					}
					if (hasVisited[nx][ny] || board[nx][ny] != 1)
					{
						continue;
					}
					hasVisited[nx][ny] = 1;
					q.push({ nx,ny });
				}
			}
			max = std::max(max, area);
		}
	}
	cout << num << "\n" << max;
}