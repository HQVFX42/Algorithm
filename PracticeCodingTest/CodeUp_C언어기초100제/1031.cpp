#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int dec;
	cin >> dec;

	vector<int> v;
	while (dec)
	{
		v.push_back(dec % 8);
		dec /= 8;
	}
	reverse(v.begin(), v.end());
	for (auto i : v)
	{
		cout << i;
	}	
}