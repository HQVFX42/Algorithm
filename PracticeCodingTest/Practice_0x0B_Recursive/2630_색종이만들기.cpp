#include <bits/stdc++.h>
using namespace std;

int board[128][128];
int ans[2];
// 2개의 색 중 어느 하나의 색으로만 가득 채워져 있다면 더 이상의 탐색이 필요하지 않다
bool check(int n, int x, int y)
{
	for (int i = x; i < x + n; i++)
	{
		for (int j = y; j < y + n; j++)
		{
			if (board[i][j] != board[x][y])	// 다른 색이 있을 경우
			{
				return false;
			}
		}
	}
	return true;
}
// 현재 길이 * 0.5로 사각형을 쪼개가면서 탐색
void cutRecursive(int n, int x, int y)
{
	if (check(n, x, y))
	{
		ans[board[x][y]]++;
		return;
	}
	int half = n * 0.5;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cutRecursive(half, x + i * half, y + j * half);	// 4가지 영역에 대한 탐색
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

	for (int i = 0; i < 2; i++)
	{
		cout << ans[i] << '\n';
	}
}