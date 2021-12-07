#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<int> q;
	int TC;
	cin >> TC;
	while (TC--)
	{
		string s;
		cin >> s;
		if (s == "push")
		{
			int n;
			cin >> n;
			q.push(n);
		}
		else if (s == "pop")
		{
			if (q.empty() == 1)
			{
				cout << "-1" << "\n";
			}
			else
			{
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (s == "size")
		{
			cout << q.size() << "\n";
		}
		else if (s == "empty")
		{
			if (q.empty() == 1)
			{
				cout << "1" << "\n";
			}
			else
			{
				cout << "0" << "\n";
			}
		}
		else if (s == "front")
		{
			if (q.empty() == 1)
			{
				cout << "-1" << "\n";
			}
			else
			{
				cout << q.front() << "\n";
			}
		}
		else if (s == "back")
		{
			if (q.empty() == 1)
			{
				cout << "-1" << "\n";
			}
			else
			{
				cout << q.back() << "\n";
			}
		}
	}
}