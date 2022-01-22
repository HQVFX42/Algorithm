#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int board[100][100] = {};
	int h, w, n, l, d, x, y;
	cin >> h >> w;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> l >> d >> x >> y;
		if (d)		// 세로
		{
			for (int j = 0; j < l; j++)
			{
				board[x + j][y] = 1;
			}
		}
		else		// 가로
		{
			for (int j = 0; j < l; j++)
			{
				board[x][y + j] = 1;
			}
		}
	}

	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
}