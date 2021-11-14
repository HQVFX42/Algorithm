#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int set[10] = {};
	int ans = 1;
	while (N)
	{
		set[N % 10]++;
		N /= 10;
	}
	for (int i = 0; i < 10; i++)
	{
		if (i == 6 || i == 9)
		{
			continue;
		}
		ans = max(ans, set[i]);
	}
	ans = max(ans, (set[6] + set[9] + 1) / 2);
	cout << ans;
}