#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[502][502] =
{
 {1,1,1,0,1,0,0,0,0,0},
 {1,0,0,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0}
};
bool vis[502][502];
int n = 7, m = 10;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	queue < pair<int, int>> q;
	vis[0][0] = 1;		// (0,0) �湮
	q.push({ 0,0 });	// ť�� ������ ����
	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();
		cout << '(' << cur.X << ", " << cur.Y << ") -> ";
		for (int dir = 0; dir < 4; dir++)		// �����¿� ĭ Ž��
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];			// nx, ny�� dir�� ���� ������ ������ ĭ ��ǥ
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)		// ���� ���� ��� �н�
			{
				continue;
			}
			if (vis[nx][ny] || board[nx][ny] != 1)			// �̹� �湮�߰ų� �Ķ�ĭ�� �ƴ� ���
			{
				continue;
			}
			vis[nx][ny] = 1;	// nx, ny �湮
			q.push({ nx,ny });
		}
	}
}