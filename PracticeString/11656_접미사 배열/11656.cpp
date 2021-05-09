#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	string s;
	cin >> s;

	int n = s.size();
	vector<string> v;
	for (int i = 0; i < n; i++)
	{
		v.push_back(s.substr(i));
		//cout << v[i] << '\n';
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
	{
		cout << v[i] << '\n';
	}

	/*int n = s.size();
	vector<int> a;
	for (int i = 0; i < n; i++) { a.push_back(i); }

	sort(a.begin(), a.end(), [&s](int u, int v) {return strcmp(s.c_str() + u, s.c_str() + v) < 0; });

	for (auto& x : a) { cout << s.substr(x) << '\n'; }*/

	return 0;
}