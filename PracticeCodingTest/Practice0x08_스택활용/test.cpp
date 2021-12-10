#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;
	cin >> str;
	stack<int> s;

	int sum = 0;
	int mul = 1;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
		{
			s.push(str[i]);
			mul *= 2;
		}
		else if (str[i] == '[')
		{
			s.push(str[i]);
			mul *= 3;
		}
		else if (str[i] == ')')
		{
			if (s.empty() || s.top() != '(')
			{
				cout << 0;
				return 0;
			}
			if (str[i - 1] == '(')
			{
				sum += mul;
			}
			s.pop();
			mul /= 2;
		}
		else if (str[i] == ']')
		{
			if (s.empty() || s.top() != '[')
			{
				cout << 0;
				return 0;
			}
			if (str[i - 1] == '[')
			{
				sum += mul;
			}
			s.pop();
			mul /= 3;
		}
	}
	if (s.empty())
	{
		cout << sum;
	}
	else
	{
		cout << 0;
	}
}