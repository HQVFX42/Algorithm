#include <bits/stdc++.h>
using namespace std;

char board[30][30][30];
int vis[30][30][30];
int dx[6] = { 1,-1,0,0,0,0 }, dy[6] = { 0,0,1,-1,0,0 }, dz[6] = { 0,0,0,0,1,-1 };
int X, Y, Z;
bool bEnd;
queue<tuple<int, int, int>> q;

void INIT()
{
	bEnd = false;
	q = queue<tuple<int, int, int>>();	//queue init
	for (int i = 0; i < Z; i++)
	{
		for (int j = 0; j < X; j++)
		{
			fill(vis[i][j], vis[i][j] + Y, 0);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while (true)
	{
		cin >> Z >> X >> Y;
		if (Z == 0 && X == 0 && Y == 0)	break;
		
		INIT();

		for (int i = 0; i < Z; i++)
		{
			for (int j = 0; j < X; j++)
			{
				for (int k = 0; k < Y; k++)
				{
					cin >> board[i][j][k];
					if (board[i][j][k] == 'S')
					{
						q.push({ i,j,k });
						vis[i][j][k] = 0;
					}
					if (board[i][j][k] == '.')
					{
						vis[i][j][k] = -1;
					}
				}
			}
		}

		while (!q.empty())
		{
			if (bEnd) break;	// 출구가 여러 개 입력될 경우 최소에서 탈출
			auto cur = q.front();	q.pop();
			int curX, curY, curZ;
			tie(curZ, curX, curY) = cur;
			for (int dir = 0; dir < 6; dir++)
			{
				/*int nx = get<1>(cur) + dx[dir];
				int ny = get<2>(cur) + dy[dir];
				int nz = get<0>(cur) + dz[dir];*/
				int nx = curX + dx[dir];
				int ny = curY + dy[dir];
				int nz = curZ + dz[dir];
				if (nx < 0 || nx >= X || ny < 0 || ny >= Y || nz < 0 || nz >= Z)
				{
					continue;
				}
				if (vis[nz][nx][ny] > 0 || board[nz][nx][ny] == '#')
				{
					continue;
				}
				//vis[nz][nx][ny] = vis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
				vis[nz][nx][ny] = vis[curZ][curX][curY] + 1;
				if (board[nz][nx][ny] == 'E')
				{
					cout << "Escaped in " << vis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1 << " minute(s).\n";
					bEnd = true;
					break;
				}
				q.push({ nz,nx,ny });
			}
		}
		
		if (bEnd == false)
		{
			cout << "Trapped!\n";
		}
	}
}