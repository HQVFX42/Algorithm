#include <bits/stdc++.h>
using namespace std;
// ���� : 1��, 256MB
// N = 3 * 2^k(0 <= k <= 10) --> 3 * 1024
char coord[3 * 1024][3 * 1024 * 2 - 1];

void PrintRecursive(int n, int x, int y)
{
	// base condition�� 3 * 2^k�̱� ������ ���� ���� �ﰢ���� 3�� ��
	if (n == 3)
	{
		// ������ �Ʒ��� �ﰢ�� ���
		coord[x][y] = '*';
		coord[x + 1][y - 1] = '*';
		coord[x + 1][y + 1] = '*';
		for (int i = y - 2; i <= y + 2; i++)
		{
			coord[x + 2][i] = '*';
		}
		return;
	}
	// 2�� �ŵ������̱� ������ 2�� ��� �����ش�
	int num = n * 0.5;
	// 3���� �ﰢ���� �� ������ �����ϱ� ������ 3�� �Լ� ȣ��
	PrintRecursive(num, x, y);
	PrintRecursive(num, x + num, y - num);
	PrintRecursive(num, x + num, y + num);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		fill(coord[i], coord[i] + N * 2 - 1, ' ');
	}
	PrintRecursive(N, 0, N - 1);
	// �ﰢ�� ����� ���� y ���� 0���� 2N - 1
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N * 2 - 1; j++)
		{
			cout << coord[i][j];
		}
		cout << '\n';
	}
}