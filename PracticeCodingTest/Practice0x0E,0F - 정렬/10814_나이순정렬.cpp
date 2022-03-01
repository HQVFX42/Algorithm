#include <bits/stdc++.h>
using namespace std;
// ���ٽ��� �̿��� Ǯ��
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
// compare �޼��带 �̿��� Ǯ��
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
// tuple�� ����� Ǯ��
void func3()
{
	int n;
	cin >> n;
	vector<tuple<int, int, string>> v;
	for (int i = 0; i < n; i++)
	{
		int age;
		string name;
		cin >> age >> name;
		v.push_back({ age,i,name });
	}
	sort(v.begin(), v.end());
	for (auto [age, b, name] : v)	// c++ 17�̻� ����
	{
		cout << age << " " << name << '\n';
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	//func1();
	//func2();
	func3();
}