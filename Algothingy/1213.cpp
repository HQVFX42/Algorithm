#include <bits/stdc++.h>

using namespace std;

void fastIO()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
}

int cnt[222];
int main()
{
	fastIO();

	string str;
	cin >> str;

	for (auto& i : str)
	{
		cnt[i]++;
	}
	
	string result;
	char mid;
	int flag = 0;
	for (int i = 'Z'; i >= 'A'; i--)
	{
		if (cnt[i] & 1)
		{
			mid = char(i);
			flag++;
			cnt[i]--;
		}

		if (flag == 2)
		{
			break;
		}

		for (int j = 0; j < cnt[i]; j += 2)
		{
			result = char(i) + result;
			result = result + char(i);
		}
	}

	if (flag == 2)
	{
		cout << "I'm Sorry Hansoo\n";
		return 0;
	}

	if (mid)
	{
		result.insert(result.begin() + result.size() / 2, mid);
	}
	cout << result << "\n";
}