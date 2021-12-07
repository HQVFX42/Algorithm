#include <bits/stdc++.h>
using namespace std;

void parse(string& num, deque<int>& dq)
{
	int cur = 0;
	for (int i = 1; i < num.size() - 1; i++)
	{
		if (num[i] == ',')
		{
			dq.push_back(cur);
			cur = 0;
		}
		else
		{
			cur = 10 * cur + (num[i] - '0');	//char to int
		}
	}
	if (cur != 0)
	{
		dq.push_back(cur);
	}
}

void print(deque<int>& dq)
{
	cout << '[';
	for (int i = 0; i < dq.size(); i++)
	{
		cout << dq[i];
		if (i != dq.size() - 1)
		{
			cout << ',';
		}
	}
	cout << "]\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int TC;
	cin >> TC;

	while (TC--)
	{
		deque<int> dq;
		string command, num;
		int size;
		bool isReverse = false, isWrong = false;
		cin >> command;
		cin >> size;
		cin >> num;
		parse(num, dq);

		for (auto c : command)
		{
			if (c == 'R')
			{
				if (isReverse)
				{
					isReverse = false;
				}
				else
				{
					isReverse = true;
				}
			}
			else
			{
				if (dq.empty())
				{
					isWrong = true;
					break;
				}
				else if (isReverse)
				{
					dq.pop_back();
				}
				else
				{
					dq.pop_front();
				}
			}
		}
		if (isWrong)
		{
			cout << "error\n";
		}
		else
		{
			if (isReverse)
			{
				reverse(dq.begin(), dq.end());
			}
			print(dq);
		}
	}
}