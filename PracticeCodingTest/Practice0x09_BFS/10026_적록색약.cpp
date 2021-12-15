#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

char board[101][101];
bool hasVisited[101][101];
int n;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void bfs(int i, int j)
{
	queue<pair<int, int>> q;
	q.push({ i,j });
	hasVisited[i][j] = 1;
	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (hasVisited[nx][ny] == 1 || board[i][j] != board[nx][ny]) continue;
			hasVisited[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
}

int area()
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!hasVisited[i][j])
			{
				cnt++;
				bfs(i, j);
			}
		}
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}
	int notCB = area();
	// ���ϻ����� ����� ���ϱ����� �湮�迭 �ʱ�ȭ
	for (int i = 0; i < n; i++)
	{
		fill(hasVisited[i], hasVisited[i] + n, false);
	}
	// ���ϻ����� �ʷ��̸� �������� ����
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == 'G')
			{
				board[i][j] = 'R';
			}
		}
	}

	int isCB = area();
	cout << notCB << " " << isCB;	
}