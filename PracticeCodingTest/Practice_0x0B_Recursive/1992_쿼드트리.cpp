#include <bits/stdc++.h>
using namespace std;
// ���� : 2��, 128MB
// N = 1~64
string coord[64];
// coord ���� �ȿ� ���Ұ� ��� �� �Ȱ����� Ȯ���Ѵ�
bool Check(int n, int x, int y)
{
	for (int i = x; i < x+n; i++)
	{
		for (int j = y; j < y+n; j++)
		{
			if (coord[i][j] != coord[x][y])
			{
				return false;
			}
		}
	}
	return true;
}
// ��ġ�ϸ� ���, ��ġ���� ������ 4����ϴ� ���
void quadRecursive(int n, int x, int y)
{
	if (Check(n, x, y))
	{
		cout << coord[x][y];
		return;
	}
	cout << '(';
	int divide = n * 0.5;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			quadRecursive(divide, x + i * divide, y + j * divide);
		}
	}
	cout << ')';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> coord[i];
	}
	quadRecursive(N, 0, 0);
}