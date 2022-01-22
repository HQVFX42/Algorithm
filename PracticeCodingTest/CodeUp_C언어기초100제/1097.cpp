#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int board[20][20] = {};
	for (int i = 1; i < 20; i++)
	{
		for (int j = 1; j < 20; j++)
		{
			cin >> board[i][j];
		}
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		for (int j = 1; j < 20; j++)
		{
			if (board[x][j] == 1)
			{
				board[x][j] = 0;
			}
			else if (board[x][j] == 0)
			{
				board[x][j] = 1;
			}
		}
		for (int j = 0; j < 20; j++)
		{
			if (board[j][y] == 1)
			{
				board[j][y] = 0;
			}
			else if (board[j][y] == 0)
			{
				board[j][y] = 1;
			}
		}
	}

	for (int i = 1; i < 20; i++)
	{
		for (int j = 1; j < 20; j++)
		{
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
}