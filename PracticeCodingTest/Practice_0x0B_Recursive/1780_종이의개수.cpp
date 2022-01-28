#include <bits/stdc++.h>
using namespace std;
// 시간 제한 2초, 메모리 제한 256MB
// 입력 값이 최대 3^7 = 2187
int board[2200][2200];
int ans[3];
// 같은 숫자로만 채워졌는지 확인한다
bool check(int n, int x, int y)
{
	for (int i = x; i < x + n; i++)
	{
		for (int j = y; j < y + n; j++)
		{
			if (board[i][j] != board[x][y])
			{
				return false;
			}
		}
	}
	return true;
}

void cutRecursive(int n, int x, int y)
{
	if (check(n, x, y))
	{
		ans[board[x][y] + 1]++;
		return;
	}
	int cut = n / 3;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cutRecursive(cut, x + i * cut, y + j * cut);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
		}
	}
	cutRecursive(N, 0, 0);
	for (int i = 0; i < 3; i++)
	{
		cout << ans[i] << '\n';
	}
}