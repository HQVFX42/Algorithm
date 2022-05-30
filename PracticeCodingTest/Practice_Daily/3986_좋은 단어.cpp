#include <bits/stdc++.h>
using namespace std;

void fastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int main()
{
	fastIO();
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		string tmp;
		cin >> tmp;
		stack<char> s;
		int tsz = tmp.size();
		for (int j = 0; j < tsz; j++)
		{
			if (!s.empty() and s.top() == tmp[j])
			{
				s.pop();
			}
			else
			{
				s.push(tmp[j]);
			}
		}
		if (s.size() == 0)
		{
			ans++;
		}
	}
	cout << ans;
}