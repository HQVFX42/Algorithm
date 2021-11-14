#include <bits/stdc++.h>
using namespace std;

int main()
{
	int TC;
	cin >> TC;

	while (TC--)
	{
		list<char> L = {};
		string s;
		auto p = L.begin();

		cin >> s;
		for (auto c : s)
		{
			if (c == '<')
			{
				if (p != L.begin())
				{
					p--;
				}
			}
			else if (c == '>')
			{
				if (p != L.end())
				{
					p++;
				}
			}
			else if (c == '-')
			{
				if (p != L.begin())
				{
					p--;
					p = L.erase(p);
				}
			}
			else
			{
				L.insert(p, c);
			}
		}
		for (auto c : L)
		{
			cout << c;
		}
		cout << "\n";
	}
}