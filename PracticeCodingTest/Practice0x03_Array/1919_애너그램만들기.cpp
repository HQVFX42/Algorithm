#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int result = 0;

	string s1, s2;
	cin >> s1 >> s2;

	int a[2][26] = {};
	for (auto c : s1)
	{
		a[0][c - 'a']++;
	}
	for (auto c : s2)
	{
		a[1][c - 'a']++;
	}

	for (int i = 0; i < 26; i++)
	{
		result += abs(a[0][i] - a[1][i]);
	}

	cout << result;
}