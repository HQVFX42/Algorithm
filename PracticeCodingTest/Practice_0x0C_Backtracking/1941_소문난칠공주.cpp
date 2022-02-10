// 2s, 256MB
// 5*5 combination 7 --> 25C7 = 480700���� ����� ��
#include <bits/stdc++.h>
using namespace std;

bool bUsed[25];	// ���ս� ���õ� �� üũ

int coord[5][5];
bool bVis[5][5];	// ���� BFS �湮 üũ
bool bSelect7[5][5];	// ĥ���ַ� ���õ� �л���
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
// ������ �ִ��� üũ
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
			// (0,0) ���� (4,4)���� 25���� ��ǥ ����
			int x = i / 5;
			int y = i % 5;
			bSelect7[x][y] = true;
			if (q.empty())	// BFS ������ ����
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
				// �������� ����ų�(OOB), �̹� �湮�� �迭�̰ų�, 7���ְ� �ƴҰ��
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
// ������ ���ϰ� �ִ��� üũ
bool HaveEdge()
{
	int cnt = 0;
	for (int i = 0; i < 25; i++)
	{
		if (bUsed[i] == true)
		{
			// 5*5 x��ǥ, y��ǥ
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