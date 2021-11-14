#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K;
	cin >> N >> K;

	int s[2][7] = {};

	for (int i = 0; i < N; i++)
	{		
		int sex, year;
		cin >> sex >> year;
		s[sex][year]++;
	}

	int ans = 0;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			ans += s[i][j] / K;
			if (s[i][j] % K)
			{
				ans++;
			}
		}
	}

	cout << ans;
}