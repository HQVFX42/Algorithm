// 2s, 512MB
// 1 <= N <= 8
#include <bits/stdc++.h>
using namespace std;

int N, ans, cnt;
int s[8], w[8];

void funcRecursive(int depth, int st)
{
	if (depth == N)
	{
		ans = max(ans, cnt);
		return;
	}
	// depth번째 달걀이 깨져있거나 다른 모든 달걀이 깨져있다면 패스
	if (s[depth] <= 0 || cnt == N - 1)
	{
		funcRecursive(depth + 1, st);
		return;
	}
	// i번째 달걀 깨기
	for (int i = st; i < N; i++)
	{
		// 현재 손에 든 달걀 또는 이미 깨진 달걀은 패스
		if (i == depth or s[i] <= 0) continue;

		s[depth] -= w[i];
		s[i] -= w[depth];
		if (s[depth] <= 0) cnt++;
		if (s[i] <= 0) cnt++;
		funcRecursive(depth + 1, st);
		if (s[depth] <= 0) cnt--;
		if (s[i] <= 0) cnt--;
		s[depth] += w[i];
		s[i] += w[depth];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> s[i] >> w[i];
	}
	funcRecursive(0, 0);
	cout << ans;
}