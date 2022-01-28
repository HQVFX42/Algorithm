#include <bits/stdc++.h>
using namespace std;

int board[128][128];
int ans[2];
// 2���� �� �� ��� �ϳ��� �����θ� ���� ä���� �ִٸ� �� �̻��� Ž���� �ʿ����� �ʴ�
bool check(int n, int x, int y)
{
	for (int i = x; i < x + n; i++)
	{
		for (int j = y; j < y + n; j++)
		{
			if (board[i][j] != board[x][y])	// �ٸ� ���� ���� ���
			{
				return false;
			}
		}
	}
	return true;
}
// ���� ���� * 0.5�� �簢���� �ɰ����鼭 Ž��
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
			cutRecursive(half, x + i * half, y + j * half);	// 4���� ������ ���� Ž��
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