#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	deque<int> d;
	int num;
	while (n--)
	{
		string cmd;
		cin >> cmd;
		if (cmd == "push_front")
		{
			cin >> num;
			d.push_front(num);
		}
		else if (cmd == "push_back")
		{
			cin >> num;
			d.push_back(num);
		}
		else if (cmd == "pop_front")
		{
			if (d.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << d.front() << '\n';
				d.pop_front();
			}
		}
		else if (cmd == "pop_back")
		{
			if (d.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << d.back() << '\n';
				d.pop_back();
			}
		}
		else if (cmd == "size")
		{
			cout << d.size() << '\n';
		}
		else if (cmd == "empty")
		{
			cout << d.empty() << '\n';
		}
		else if (cmd == "front")
		{
			if (d.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << d.front() << '\n';
			}
		}
		else if (cmd == "back")
		{
			if (d.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << d.back() << '\n';
			}
		}
	}
}