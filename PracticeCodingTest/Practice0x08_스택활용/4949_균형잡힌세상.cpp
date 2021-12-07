#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while (true)
	{
		string s;
		getline(cin, s);
		if (s == ".")
		{
			break;
		}

		stack<char> ans;
		bool isValid = true;
		for (auto c : s)
		{
			if (c == '(' || c == '[')
			{
				ans.push(c);
			}
			else if (c == ')')
			{
				if (ans.empty() || ans.top() != '(')
				{
					isValid = false;
					break;
				}
				ans.pop();
			}
			else if (c == ']')
			{
				if (ans.empty() || ans.top() != '[')
				{
					isValid = false;
					break;
				}
				ans.pop();
			}
		}

		if (!ans.empty())
		{
			isValid = false;
		}
		if (isValid)
		{
			cout << "yes\n";
		}
		else
		{
			cout << "no\n";
		}
	}
}