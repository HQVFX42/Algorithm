#include <bits/stdc++.h>
using namespace std;

void fastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int main()
{
	fastIO();
	string s;
	getline(cin, s);
	int sz = s.size();
	for (int i = 0; i < sz; i++)
	{
		if (s[i] >= 'A' and s[i] <= 'Z')
		{
			if (s[i] + 13 > 'Z')
			{
				s[i] -= 13;
			}
			else
			{
				s[i] += 13;
			}
		}
		else if (s[i] >= 'a' and s[i] <= 'z')
		{
			if (s[i] + 13 > 'z')
			{
				s[i] -= 13;
			}
			else
			{
				s[i] += 13;
			}
		}
		cout << s[i];
	}
}