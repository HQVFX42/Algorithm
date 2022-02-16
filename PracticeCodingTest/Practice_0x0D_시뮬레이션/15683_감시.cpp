// 1s, 512MB
// 8 * 8
#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 1,-1,0,0, }, dy[4] = { 0,0,1,-1 };
int n, m, ans;
int coord[8][8];
int camState[8][8];
vector<pair<int, int>> vCamCoord;

bool OOB(int a, int b)
{
	return a < 0 or a >= n or b < 0 or b >= m;
}

void func(int x, int y, int dir)
{
	dir %= 4;
	while (true)
	{
		x += dx[dir];
		y += dy[dir];
		if (OOB(x, y) or camState[x][y] == 6) return;
		if (camState[x][y] != 0) continue;
		camState[x][y] = 7;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> coord[i][j];
			if (coord[i][j] != 0 and coord[i][j] != 6)
			{
				vCamCoord.push_back({ i,j });
			}
			if (coord[i][j] == 0) ans++;
		}
	}

	int CCSZ = vCamCoord.size();
	for (int tmp = 0; tmp < (1 << (2 * CCSZ)); tmp++)	// 4Áø¹ý
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				camState[i][j] = coord[i][j];
			}
		}
		int brute = tmp;
		for (int i = 0; i < CCSZ; i++)
		{
			int dir = brute % 4;
			brute /= 4;
			int x, y;
			tie(x, y) = vCamCoord[i];
			switch (coord[x][y])
			{
			case 1:
				func(x, y, dir);
				break;
			case 2:
				func(x, y, dir);
				func(x, y, dir + 2);
				break;
			case 3:
				func(x, y, dir);
				func(x, y, dir + 1);
				break;
			case 4:
				func(x, y, dir);
				func(x, y, dir + 1);
				func(x, y, dir + 2);
				break;
			default:
				func(x, y, dir);
				func(x, y, dir + 1);
				func(x, y, dir + 2);
				func(x, y, dir + 3);
				break;
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cnt += (camState[i][j] == 0);
			}
		}
		ans = min(ans, cnt);
	}
	cout << ans;
}