// 2s, 512MB
// 40 * 40, 10 * 10, 1 <= K <= 100
#include <bits/stdc++.h>
using namespace std;

int N, M, K, R, C, ans;
int laptop[44][44], sticker[11][11];
// sitcker �迭 ��� üũ�� ���� �޼���
void print()
{
	cout << '\n';
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << sticker[i][j] << ' ';
		}
		cout << '\n';
	}
}
// Sticker �Է�
void inputSticker()
{
	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> sticker[i][j];
		}
	}

}
// ��Ʈ���� (i,j)�� (0,0)�� �ö󰡰� ��ƼĿ�� ���� �� �ִ��� �Ǵ�
bool canPaste(int x, int y)
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (sticker[i][j] == 1 and laptop[x + i][y + j] == 1) return false;
		}
	}
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (sticker[i][j] == 1) laptop[x + i][y + j] = 1;
		}
	}
	return true;
}
void rotate90()
{
	int tmp[11][11];
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			tmp[i][j] = sticker[i][j];
		}
	}
	for (int i = 0; i < C; i++)
	{
		for (int j = 0; j < R; j++)
		{
			sticker[i][j] = tmp[R - 1 - j][i];
		}
	}
	swap(R, C);
	//print();
}
// 0�� ���� 270�� ���� ȸ���غ��鼭 ���� �� �ִ� �� Ž��
void func()
{
	for (int dir = 0; dir < 4; dir++)
	{
		bool bPasted = false;
		for (int i = 0; i <= N - R; i++)	//(i,j)�� ���������� ��ƼĿ�� �ٿ�����
		{
			if (bPasted) break;		// �ش� ��ƼĿ�� �ٿ��ٸ� break
			for (int j = 0; j <= M - C; j++)
			{
				if (canPaste(i, j))
				{
					bPasted = true;
					break;
				}
			}
		}
		if (bPasted) break;
		rotate90();	// �� �ٿ��ٸ� ȸ��
	}
}
// ��ƼĿ�� �پ� �ִ� ĭ�� ����
void output()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			ans += laptop[i][j];
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;
	while (K--)
	{
		inputSticker();
		func();
	}
	output();
}