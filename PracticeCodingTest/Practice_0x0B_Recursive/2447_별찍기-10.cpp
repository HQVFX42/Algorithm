#include <bits/stdc++.h>
using namespace std;
// ���� : 1��, 256MB
// N^k K = 1~7 : 2187

// NULL ��� ���鹮�ڰ� ���� ��� ���ʿ��� ������ �߰��� ��µ� �� �ִ�.
// ���� ���� ���� �ʱ� ���� NULL
char coord[2200][2200];	

void PrintStar2(int n, int x, int y)
{
	if (n == 1)
	{
		coord[x][y] = '*';
		return;
	}
	int divide = n / 3;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == 1 && j == 1)
			{
				continue;
			}
			PrintStar2(divide, x + i * divide, y + j * divide);
		}
	}
}
void PrintStar1(int n, int i, int j)
{
	if ((i / n) % 3 == 1 && (j / n) % 3 == 1)
	{
		cout << ' ';
	}
	else
	{
		if (n / 3 == 0)
		{
			cout << '*';
		}
		else
		{
			PrintStar1(n / 3, i, j);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	// PrintStar2
	/*for (int i = 0; i < N; i++)
	{
		fill(coord[i], coord[i] + N, ' ');
	}
	PrintStar2(N, 0, 0);
	for (int i = 0; i < N; i++)
	{
		cout << coord[i] << '\n';
	}*/

	// PrintStar1
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			PrintStar1(N, i, j);
		}
		cout << '\n';
	}
}