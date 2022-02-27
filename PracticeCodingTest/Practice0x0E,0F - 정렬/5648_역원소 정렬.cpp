#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	while (n--)
	{
		string tmp;
		cin >> tmp;
		reverse(tmp.begin(), tmp.end());
		v.push_back(stoll(tmp));
	}
	sort(v.begin(), v.end());
	for (auto& i : v)
	{
		cout << i << '\n';
	}
}