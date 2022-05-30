#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int main()
{
	fastIO();
	int TC;
	cin >> TC;
	while (TC--)
	{
		int n;
		cin >> n;
		map<string, int> m;
		string s1, s2;
		for (int i = 0; i < n; i++)
		{
			cin >> s1 >> s2;
			m[s2]++;
		}
		ll ans = 1;
		for (auto& i : m)
		{	// 선택을 하지 않을 경우도 있기 때문에 +1의 조합을 생각
			ans *= i.second + 1;
		}
		ans--;	// 아무것도 입지 않은 경우 제외
		cout << ans << '\n';
	}
}