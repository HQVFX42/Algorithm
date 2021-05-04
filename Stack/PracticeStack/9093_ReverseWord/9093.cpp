#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	cin.ignore();
	
	while (t--)
	{
		string str;
		getline(cin, str);
		str += '\n';
		stack<char> s;
		for (char ch : str)
		{
			if (ch == ' ' || ch == '\n')
			{
				while (!s.empty())
				{
					cout << s.top();
					s.pop();
				}
				cout << ch;
			}
			else
			{
				s.push(ch);
			}
		}
	}
	return 0;
}