#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int main()
{
	fastIO();
	int TC;
	cin >> TC;
	while (TC--)
	{
		int n;
		cin >> n;
		map<string, int> m;
		string s1, s2;
		for (int i = 0; i < n; i++)
		{
			cin >> s1 >> s2;
			m[s2]++;
		}
		ll ans = 1;
		for (auto& i : m)
		{	// ������ ���� ���� ��쵵 �ֱ� ������ +1�� ������ ����
			ans *= i.second + 1;
		}
		ans--;	// �ƹ��͵� ���� ���� ��� ����
		cout << ans << '\n';
	}
}