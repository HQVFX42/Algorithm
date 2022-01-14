#include <bits/stdc++.h>
using namespace std;

int board[102][102];
int vis[102][102];
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1, -1 };
int m, n, k, x, y, xx, yy;
queue<pair<int, int>> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> m >> n >> k;
	while (k--)
	{
		cin >> x >> y >> xx >> yy;
		for (int i = y; i < yy; i++)
		{
			for (int j = x; j < xx; j++)
			{
				board[i][j] = 1;
			}
		}
	}

	int num = 0;
	vector<int> ans;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == 1 || vis[i][j] == 1)
			{
				continue;
			}
			vis[i][j] = 1;
			q.push({ i,j });
			int width = 1;
			num++;
			while (!q.empty())
			{
				auto cur = q.front();	q.pop();
				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.first + dx[dir], ny = cur.second + dy[dir];
					if (nx < 0 || nx >= m || ny < 0 || ny >= n)
					{
						continue;
					}
					if (vis[nx][ny] == 1 || board[nx][ny] == 1)
					{
						continue;
					}
					vis[nx][ny] = 1;
					q.push({ nx,ny });
					width++;
				}
			}
			ans.push_back(width);
		}
	}
	cout << num << '\n';
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << ' ';
	}
}