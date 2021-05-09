#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	string s;
	vector<string> v;
	string* p;

	while (getline(cin, s))
	{
		v.push_back(s);
		if (s.find("one"))
		{
			cout << 1;
		}

		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i] << '\n';
		}
	}
}