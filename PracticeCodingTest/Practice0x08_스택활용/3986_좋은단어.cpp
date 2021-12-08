#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int ans = 0;
	int TC;
	cin >> TC;
	while (TC--)
	{
		string str;
		cin >> str;

		stack<int> s;

		for (auto c : str)
		{
			if (!s.empty() && s.top() == c)
			{
				s.pop();
			}
			else
			{
				s.push(c);
			}
		}
		if (s.empty())
		{
			ans++;
		}
	}
	cout << ans;
}