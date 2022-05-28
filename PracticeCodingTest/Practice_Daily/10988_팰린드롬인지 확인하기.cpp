#include <bits/stdc++.h>
using namespace std;

void fastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int cnt[111];

int main()
{
	fastIO();
	string s, tmp;
	cin >> s;
	tmp = s;
	reverse(tmp.begin(), tmp.end());
	if (tmp == s)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
}