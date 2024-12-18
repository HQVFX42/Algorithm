#include <bits/stdc++.h>

using namespace std;

void fastIO()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
}

int main()
{
	fastIO();

	int n;
	cin >> n;
	
	int ans = 0;
	while (n--)
	{
		string str;
		cin >> str;

		stack<char> stack;
		for (auto& i : str)
		{
			if (!stack.empty() and stack.top() == i)
			{
				stack.pop();
			}
			else
			{
				stack.push(i);
			}
		}

		if (stack.empty())
		{
			ans++;
		}
	}

	cout << ans;
}