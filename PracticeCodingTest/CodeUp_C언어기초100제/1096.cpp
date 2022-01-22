#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int board[20][20] = {};
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		board[x][y] = 1;
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