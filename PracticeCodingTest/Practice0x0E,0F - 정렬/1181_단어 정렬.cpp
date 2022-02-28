#include <bits/stdc++.h>
using namespace std;
// map을 이용한 풀이
void solution1()
{
	int n;
	map<string, int> m[55];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		m[s.length()].insert({ s, 0 });
	}
	for (int i = 0; i < 55; i++)
	{
		if (m[i].empty()) continue;
		for (auto iter = m[i].begin(); iter != m[i].end(); iter++)
		{
			cout << iter->first << '\n';
		}
	}
}
// vector를 이용한 풀이
void solution2()
{
	int n;
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end(), [](const string& lhs, const string& rhs)
		{
			if (lhs.length() != rhs.length()) return lhs.length() < rhs.length();	// 길이가 다르면 길이순
			return lhs < rhs;	// 길이가 같으면 사전순
		});
	v.erase(unique(v.begin(), v.end()), v.end());	// 중복 원소 제거
	for (string& s : v) cout << s << '\n';
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	//solution1();
	solution2();
}