#include <bits/stdc++.h>
using namespace std;

string board[25];
int vis[25][25];
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
int n;
queue<pair<int, int>> q;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> board[i];
	}

	int count = 0;
	vector<int> ans;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == '0' || vis[i][j] == 1) continue;
			vis[i][j] = 1;
			q.push({ i,j });
			count++;
			int width = 1;
			while (!q.empty())
			{
				auto cur = q.front(); q.pop();
				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.first + dx[dir], ny = cur.second + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (board[nx][ny] == '0' || vis[nx][ny] == 1) continue;
					vis[nx][ny] = 1;
					q.push({ nx,ny });
					width++;
				}
			}
			ans.push_back(width);
		}
	}
	cout << count << '\n';
	for (auto i : ans) cout << i << '\n';
}