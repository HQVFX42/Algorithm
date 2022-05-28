#include <bits/stdc++.h>
using namespace std;

void fastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int cnt[26];

int main()
{
	fastIO();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		cnt[s[0] - 'a']++;
	}

	string ans;
	for (int i = 0; i < 26; i++)
	{
		if (cnt[i] >= 5)
		{
			ans += i + 'a';
		}
	}
	if (!ans.empty()) cout << ans;
	else cout << "PREDAJA";
}