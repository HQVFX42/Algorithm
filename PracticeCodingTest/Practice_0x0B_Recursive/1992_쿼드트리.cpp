#include <bits/stdc++.h>
using namespace std;
// 제한 : 2초, 128MB
// N = 1~64
string coord[64];
// coord 범위 안에 원소가 모두 다 똑같은지 확인한다
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
// 일치하면 출력, 일치하지 않으면 4등분하는 재귀
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