#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
bool OOB(int x, int y, int n, int m) { return x < 0 or x >= n or y < 0 or y >= m; }
void FastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int main()
{
	FastIO();

	while (true)
	{
		string Str = "";
		getline(cin, Str);
		if (Str == ".")
		{
			break;
		}

		stack<char> Stk;
		bool bValid = true;
		for (auto & C : Str)
		{
			if (C == '(' or C == '[')
			{
				Stk.push(C);
			}
			else if (C == ')')
			{
				if (Stk.empty() or Stk.top() != '(')
				{
					bValid = false;
					break;
				}
				Stk.pop();
			}
			else if (C == ']')
			{
				if (Stk.empty() or Stk.top() != '[')
				{
					bValid = false;
					break;
				}
				Stk.pop();
			}
		}

		if (bValid and Stk.empty())
		{
			cout << "yes" << '\n';
		}
		else
		{
			cout << "no" << '\n';
		}
	}
}