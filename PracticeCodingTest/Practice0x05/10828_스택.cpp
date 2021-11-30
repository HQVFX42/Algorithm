#include<bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX];
int pos = 0;

void push(int x)
{
	dat[pos++] = x;
}
void pop()
{
	if (pos != 0)
	{
		cout << dat[pos-1] << "\n";
		pos--;
	}
	else
	{
		cout << "-1" << "\n";
	}
}
void size()
{
	cout << pos << "\n";
}
void empty()
{
	if (pos != 0)
	{
		cout << "0" << "\n";
	}
	else
	{
		cout << "1" << "\n";
	}
}
void top()
{
	if (pos != 0)
	{
		cout << dat[pos-1] << "\n";
	}
	else
	{
		cout << "-1" << "\n";
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int TC;
	cin >> TC;
	while (TC--)
	{
		string s;
		cin >> s;
		if (s == "push")
		{
			int a;
			cin >> a;
			push(a);
		}
		else if (s == "pop")
		{
			pop();
		}
		else if (s == "size")
		{
			size();
		}
		else if (s == "empty")
		{
			empty();
		}
		else if (s == "top")
		{
			top();
		}
	}
}