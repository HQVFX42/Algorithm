#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;

	/*for (char a = 'a'; a <= 'z'; a++)
	{
		int count = 0;
		for (auto c:s)
		{
			if (a == c)
			{
				count++;
			}
		}
		cout << count << ' ';
	}*/

	int freq[26] = {};

	for (auto c : s)
	{
		freq[c - 'a']++;
	}
	for (int i = 0; i < 26; i++)
	{
		cout << freq[i] << ' ';
	}
}