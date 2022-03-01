#include <bits/stdc++.h>
using namespace std;
// 완전 탐색
void solution1()
{
	int TC;
	cin >> TC;
	while (TC--)
	{
		int n, m;
		cin >> n >> m;
		vector<pair<int, int>> v(n + m);
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			v[i] = { a,0 };
		}
		for (int i = n; i < n + m; i++)
		{
			int b;
			cin >> b;
			v[i] = { b,1 };
		}
		sort(v.begin(), v.end());
		int cnt = 0;	// 현재까지 나온 b의 개수
		int ans = 0;
		for (int i = 0; i < n + m; i++)
		{
			if (v[i].second == 0) ans += cnt;	// A집합
			else cnt++;	// B집합
		}
		cout << ans << '\n';
	}
}
// 이분 탐색
void solution2()
{
	int TC;
	cin >> TC;
	while (TC--)
	{
		int n, m;
		cin >> n >> m;
		vector<int> v(n);
		for (int i = 0; i < n; i++) cin >> v[i];
		sort(v.begin(), v.end());
		int ans = 0;
		for (int i = 0; i < m; i++)
		{
			int b;
			cin >> b;
			// b보다 큰 숫자가 배열(A집합)에서 처음 등장하는 위치
			int index = upper_bound(v.begin(), v.end(), b) - v.begin();
			ans += n - index;
		}
		cout << ans << '\n';
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	//solution1();
	solution2();
}