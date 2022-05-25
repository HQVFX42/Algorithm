#include <bits/stdc++.h>
using namespace std;

void fastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int h[9];

int main()
{
	fastIO();
	string s;
	cin >> s;
	int cnt[26] = {0,};
	for (char& c : s)
	{
		cnt[c - 'a']++;
	}
	for (int i = 0; i < 26; i++)
	{
		cout << cnt[i] << ' ';
	}
}