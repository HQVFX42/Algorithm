#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int ans = 0;
	bool isLaser = false;
	string str;
	cin >> str;
	stack<int> s;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
		{
			s.push(str[i]);
		}
		else
		{
			if (str[i - 1] == '(')	//Laser
			{
				s.pop();
				ans += s.size();
			}
			else					//stick
			{
				s.pop();
				ans++;
			}
		}
	}
	cout << ans;
}