#include <iostream>
#include <string>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string s;
	cin >> s;
	unsigned int n = s.size();
	if (n%3==1)
	{
		cout << s[0];
	}
	else if (n % 3 == 2)
	{
		cout << (s[0] - '0') * 2 + (s[1] - '0');
	}
	for (unsigned int i = n % 3; i < n; i+=3)
	{
		cout << (s[i] - '0') * 4 + (s[i + 1] - '0') * 2 + (s[i + 2] - '0');
	}

	return 0;
}

