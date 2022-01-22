#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int board[12][12] = {};
	int xx, yy;
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 2)
			{
				xx = i;
				yy = j;
			}
		}
	}

	int x = 2, y = 2;
	while (true)
	{
		board[x][y] = 9;
		if (x == xx && y == yy)
		{
			break;
		}
		if (board[x][y + 1] != 1)
		{
			y++;
		}
		else if (board[x + 1][y] != 1)
		{
			x++;
		}
		else
		{
			break;
		}
	}

	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
}