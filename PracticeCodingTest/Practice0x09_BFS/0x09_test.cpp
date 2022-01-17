#include <bits/stdc++.h>
using namespace std;

int board[102][102], vis[102][102];
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
int m, n, k;
queue<pair<int, int>> q;
int count1;
vector<int> ans;

int main()
{
	cin >> m >> n >> k;
	while (k--)
	{
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = y1; i < y2; i++)
		{
			for (int j = x1; j < x2; j++)
			{
				board[i][j] = 1;
			}
		}
	}
	/*int count = 0;
	vector<int> ans;*/
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
			count1++;
			int width = 1;
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
					if (board[nx][ny] == 1 || vis[nx][ny] == 1)
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
	sort(ans.begin(), ans.end());
	cout << count1 << '\n';
	for (auto i : ans)	cout << i << ' ';
}