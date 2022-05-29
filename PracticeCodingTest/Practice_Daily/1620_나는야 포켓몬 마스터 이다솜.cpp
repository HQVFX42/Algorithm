#include <bits/stdc++.h>
using namespace std;

void fastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int main()
{
	fastIO();
	int n, m;
	cin >> n >> m;
	map<string, int> m1;
	map<int, string> m2;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		m1[s] = i + 1;
		m2[i + 1] = s;
	}
	for (int i = 0; i < m; i++)
	{
		string s;
		cin >> s;

		if (atoi(s.c_str()) == 0)
		{	// �����϶�(atoi�� ���ڸ� ������ 0�� return)
			cout << m1[s] << '\n';
		}
		else
		{	// �����϶�
			cout << m2[atoi(s.c_str())] << '\n';
		}
	}
}