// 2s, 256MB
// 5*5 combination 7 --> 25C7 = 480700가지 경우의 수
#include <bits/stdc++.h>
using namespace std;

bool bUsed[25];	// 조합시 선택된 수 체크

int coord[5][5];
bool bVis[5][5];	// 기존 BFS 방문 체크
bool bSelect7[5][5];	// 칠공주로 선택된 학생들
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
int ans;
queue<pair< int, int >> q;

void Input()
{
	for (int i = 0; i < 5; i++)
	{
		string input;
		cin >> input;
		for (int j = 0; j < 5; j++)
		{
			if (input[j] == 'Y') coord[i][j] = 1;
			else if (input[j] == 'S') coord[i][j] = 2;
		}
	}
}
// 인접해 있는지 체크
bool IsAdj()
{
	// Array Init
	for (int i = 0; i < 5; i++)
	{
		fill(bVis[i], bVis[i] + 5, 0);
		fill(bSelect7[i], bSelect7[i] + 5, 0);
	}

	for (int i = 0; i < 25; i++)
	{
		if (bUsed[i] == true)
		{
			// (0,0) 부터 (4,4)까지 25개의 좌표 대입
			int x = i / 5;
			int y = i % 5;
			bSelect7[x][y] = true;
			if (q.empty())	// BFS 시작점 설정
			{
				q.push({ x,y });
				bVis[x][y] = true;
			}
		}
	}

	int cnt = 1;
	while (!q.empty())
	{
		int x, y;
		tie(x, y) = q.front();
		q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = x + dx[dir], ny = y + dy[dir];
			if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || bVis[nx][ny] == true || bSelect7[nx][ny] == false)
			{
				// 범위에서 벗어났거나(OOB), 이미 방문한 배열이거나, 7공주가 아닐경우
				continue;
			}
			cnt++;
			q.push({ nx,ny });
			bVis[nx][ny] = true;
		}
	}
	if (cnt == 7) return true;
	return false;
}
// 우위를 점하고 있는지 체크
bool HaveEdge()
{
	int cnt = 0;
	for (int i = 0; i < 25; i++)
	{
		if (bUsed[i] == true)
		{
			// 5*5 x좌표, y좌표
			int x = i / 5;
			int y = i % 5;
			if (coord[x][y] == 2) cnt++;
		}
	}
	if (cnt >= 4) return true;
	else return false;
}
// backtracking DFS
void FuncRecursive(int depth, int start)
{
	if (depth == 7)
	{
		if (HaveEdge() == true)
		{
			if (IsAdj() == true) ans++;
		}
		return;
	}
	for (int i = start; i < 25; i++)
	{
		if (bUsed[i] == false)
		{
			bUsed[i] = true;
			FuncRecursive(depth + 1, i);
			bUsed[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	Input();
	FuncRecursive(0, 0);
	cout << ans;
}