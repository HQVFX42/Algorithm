#include <bits/stdc++.h>
using namespace std;
// 제한 : 1초, 256MB
// N = 3 * 2^k(0 <= k <= 10) --> 3 * 1024
char coord[3 * 1024][3 * 1024 * 2 - 1];

void PrintRecursive(int n, int x, int y)
{
	// base condition은 3 * 2^k이기 때문에 제일 작은 삼각형인 3일 때
	if (n == 3)
	{
		// 위부터 아래로 삼각형 모양
		coord[x][y] = '*';
		coord[x + 1][y - 1] = '*';
		coord[x + 1][y + 1] = '*';
		for (int i = y - 2; i <= y + 2; i++)
		{
			coord[x + 2][i] = '*';
		}
		return;
	}
	// 2의 거듭제곱이기 때문에 2로 계속 나눠준다
	int num = n * 0.5;
	// 3개의 삼각형이 세 점에서 시작하기 때문에 3번 함수 호출
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
	// 삼각형 출력을 위해 y 값은 0부터 2N - 1
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N * 2 - 1; j++)
		{
			cout << coord[i][j];
		}
		cout << '\n';
	}
}