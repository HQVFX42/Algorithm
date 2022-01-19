#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;
	
	int ans = 0;
	for (int i = 0; i < s.size(); i++)
	{
		ans += (s[i]-'0') * pow(8, s.size() - i - 1);
	}
	cout << ans;
}