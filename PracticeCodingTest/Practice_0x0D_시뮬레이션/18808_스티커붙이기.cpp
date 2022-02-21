// 2s, 512MB
// 40 * 40, 10 * 10, 1 <= K <= 100
#include <bits/stdc++.h>
using namespace std;

int N, M, K, R, C, ans;
int laptop[44][44], sticker[11][11];
// sitcker 배열 모양 체크를 위한 메서드
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
// Sticker 입력
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
// 노트북의 (i,j)에 (0,0)이 올라가게 스티커를 붙일 수 있는지 판단
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
// 0도 부터 270도 까지 회전해보면서 붙일 수 있는 지 탐색
void func()
{
	for (int dir = 0; dir < 4; dir++)
	{
		bool bPasted = false;
		for (int i = 0; i <= N - R; i++)	//(i,j)를 시작점으로 스티커를 붙여본다
		{
			if (bPasted) break;		// 해당 스티커를 붙였다면 break
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
		rotate90();	// 못 붙였다면 회전
	}
}
// 스티커가 붙어 있는 칸을 센다
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