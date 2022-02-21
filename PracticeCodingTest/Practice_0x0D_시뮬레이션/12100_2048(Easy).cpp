// 1s, 512MB
// 20 * 20
#include <bits/stdc++.h>
using namespace std;

int board1[22][22], board2[22][22];
int n, ans;

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board1[i][j];
		}
	}
}
void rotate90()
{
	int tmp[22][22];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			tmp[i][j] = board2[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			board2[i][j] = tmp[n - 1 - j][i];
		}
	}
}
// �������� �б�
void merge(int dir)
{
	while (dir--) rotate90();
	for (int i = 0; i < n; i++)
	{
		int merged[22] = {};	// �������� �� ��ϵ��� ���ο� �迭�� ����
		int idx = 0;	// ���� merged���� ����� �� �� �ִ� ��ġ
		for (int j = 0; j < n; j++)
		{
			if (board2[i][j] == 0) continue;
			if (merged[idx] == 0) merged[idx] = board2[i][j]; // ������ ��ġ�� ����ִ� ��� �� ����� ����
			else if (merged[idx] == board2[i][j]) merged[idx++] *= 2;	// ���� ���� ���� ��� �浹�ϴ� ��� merge
			else merged[++idx] = board2[i][j];	// 0�� �ƴ϶�� idx�� ����Ű�� ���� ���� �߰��Ǿ� �ٸ� ���� ���� ���
		}
		for (int j = 0; j < n; j++) board2[i][j] = merged[j]; // board2[i]�� merged �����
	}
}
void func()
{
	for (int tmp = 0; tmp < 1024; tmp++)
	{
		// ��� �������ְ� ������� �ϱ� ������ ���縦 ���ش�
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				board2[i][j] = board1[i][j];
			}
		}
		int brute = tmp;
		// �ִ� 5�� �̵����Ѽ� 4�������� �о��ش�
		for (int i = 0; i < 5; i++)
		{
			int dir = brute % 4;
			brute /= 4;
			merge(dir);
		}
		// ���� �� �ִ� ���� ū ���
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				ans = max(ans, board2[i][j]);
			}
		}
	}
	cout << ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	input();
	func();
}