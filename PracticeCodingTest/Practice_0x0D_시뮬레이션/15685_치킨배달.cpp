// 1s, 512MB
// 50 * 50 --> 100 * 13 * 13C6 = 2230800
#include <bits/stdc++.h>
using namespace std;

int n, m, ans = 0x7f7f7f7f;
int board[55][55];
vector<pair<int, int>> vChicken;
vector<pair<int, int>> vHouse;

void input()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 1) vHouse.push_back({ i,j });
			if (board[i][j] == 2) vChicken.push_back({ i,j });
		}
	}
}

void func()
{
	vector<int> vBrute(vChicken.size(), 1);
	fill(vBrute.begin(), vBrute.begin() + vChicken.size() - m, 0);
	do
	{
		int dist = 0;
		for (auto& h : vHouse)
		{
			int tmp = 0x7f7f7f7f;
			for (int i = 0; i < vChicken.size(); i++)
			{
				if (vBrute[i] == 0) continue;
				tmp = min(tmp, abs(vChicken[i].first - h.first) + abs(vChicken[i].second - h.second));
			}
			dist += tmp;
		}
		ans = min(ans, dist);
	} while (next_permutation(vBrute.begin(), vBrute.end()));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	input();
	func();
	cout << ans;
}