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
	{	// ����� ���� ������ �� ��� ���������� �ռ��� ���� ����ϱ� ���� Z to A
		if (cnt[i])
		{
			if (cnt[i] & 1)
			{	// ���ڰ� Ȧ������ ��� ����� ���� �ֱ� ����
				mid = char(i);
				odd++;
				cnt[i]--;
			}
			if (odd == 2)
			{	// Ȧ������ ���ڰ� 2�� �̻��̸� �Ӹ���� �Ұ�
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