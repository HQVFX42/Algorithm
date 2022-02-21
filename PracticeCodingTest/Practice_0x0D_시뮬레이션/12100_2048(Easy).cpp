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
// 한쪽으로 밀기
void merge(int dir)
{
	while (dir--) rotate90();
	for (int i = 0; i < n; i++)
	{
		int merged[22] = {};	// 한쪽으로 민 블록들을 새로운 배열에 저장
		int idx = 0;	// 다음 merged에서 블록이 들어갈 수 있는 위치
		for (int j = 0; j < n; j++)
		{
			if (board2[i][j] == 0) continue;
			if (merged[idx] == 0) merged[idx] = board2[i][j]; // 삽입할 위치가 비어있는 경우 새 블록을 저장
			else if (merged[idx] == board2[i][j]) merged[idx++] *= 2;	// 같은 값을 갖는 블록 충돌하는 경우 merge
			else merged[++idx] = board2[i][j];	// 0이 아니라면 idx가 가리키는 곳이 새로 추가되어 다른 값을 갖는 블록
		}
		for (int j = 0; j < n; j++) board2[i][j] = merged[j]; // board2[i]에 merged 덮어쓰기
	}
}
void func()
{
	for (int tmp = 0; tmp < 1024; tmp++)
	{
		// 계속 움직여주고 합쳐줘야 하기 때문에 복사를 해준다
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				board2[i][j] = board1[i][j];
			}
		}
		int brute = tmp;
		// 최대 5번 이동시켜서 4방향으로 밀어준다
		for (int i = 0; i < 5; i++)
		{
			int dir = brute % 4;
			brute /= 4;
			merge(dir);
		}
		// 얻을 수 있는 가장 큰 블록
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