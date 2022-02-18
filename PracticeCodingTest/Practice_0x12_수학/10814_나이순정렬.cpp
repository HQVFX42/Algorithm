#include <bits/stdc++.h>
using namespace std;

void func1()
{
	int n;
	cin >> n;
	vector<pair<int, string>> v(n);
	for (auto& i : v)
	{
		cin >> i.first >> i.second;
	}
	stable_sort(v.begin(), v.end(),
		[&](pair<int, string> a, pair<int, string> b) {return a.first < b.first; });
	for (auto& i : v)
	{
		cout << i.first << ' ' << i.second << '\n';
	}
}

bool compare(const pair<int, string>& lhs, const pair<int, string>& rhs)
{
	return lhs.first < rhs.first;
}
void func2()
{
	int n;
	cin >> n;
	vector<pair<int, string>> v(n);
	for (auto& i : v)
	{
		cin >> i.first >> i.second;
	}
	stable_sort(v.begin(), v.end(), compare);
	for (auto i : v)
	{
		cout << i.first << ' ' << i.second << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	//func1();
	func2();
}