#include <bits/stdc++.h>
using namespace std;

void fastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int cnt[111];

int main()
{
	fastIO();
	string s;
	cin >> s;
	for (auto& i : s)
	{
		cnt[i]++;
	}
	char mid = {};
	int odd = 0;
	string ans = {};
	for (int i = 'Z'; i >= 'A'; i--)
	{	// 경우의 수가 여러개 일 경우 사전순으로 앞서는 것을 출력하기 위해 Z to A
		if (cnt[i])
		{
			if (cnt[i] & 1)
			{	// 문자가 홀수개일 경우 가운데로 집어 넣기 위함
				mid = char(i);
				odd++;
				cnt[i]--;
			}
			if (odd == 2)
			{	// 홀수개인 문자가 2개 이상이면 팰린드롬 불가
				break;
			}
			for (int j = 0; j < cnt[i]; j += 2)
			{
				ans = char(i) + ans;
				ans += char(i);
			}
		}
	}
	if (mid)
	{
		ans.insert(ans.begin() + ans.size() * 0.5, mid);
	}
	if (odd == 2)
	{
		cout << "I'm Sorry Hansoo";
	}
	else
	{
		cout << ans;
	}
}