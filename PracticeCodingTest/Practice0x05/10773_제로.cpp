#include<bits/stdc++.h>
using namespace std;

int main()
{
	int TC;
	cin >> TC;
	stack<int> s;
	while (TC--)
	{
		int n;
		cin >> n;
		if (n != 0)
		{
			s.push(n);
		}
		else
		{
			s.pop();
		}
	}

	int result = 0;
	while (!s.empty())
	{
		result += s.top();
		s.pop();
	}
	cout << result;
}