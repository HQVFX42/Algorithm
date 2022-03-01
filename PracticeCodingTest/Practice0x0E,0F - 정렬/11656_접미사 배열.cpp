#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;
	cin >> str;
	vector<string> v;
	for (int i = 0; i < str.length(); i++)
	{
		string tmp = str.substr(i);
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	for (auto& i : v)
	{
		cout << i << '\n';
	}
}