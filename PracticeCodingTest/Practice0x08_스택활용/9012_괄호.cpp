#include <bits/stdc++.h>
using namespace std;

string isValid(string str)
{
	stack<int> s;
	for (auto c : str)
	{
		if (c == '(')
		{
			s.push(c);
		}
		else
		{
			if (s.empty() || s.top() != '(')
			{
				return "NO";
			}
			s.pop();
		}
	}
	if (s.empty())
	{
		return "YES";
	}
	else
	{
		return "NO";
	}

}

int main()
{
	int TC;
	cin >> TC;
	while (TC--)
	{
		string str;
		cin >> str;
		cout << isValid(str) << "\n";
	}
}