#include <iostream>

using namespace std;

int main()
{
	string s;
	unsigned int base;
	cin >> s >> base;
	unsigned int result = 0;
	for (unsigned int i = 0; i < s.size(); i++)
	{
		if ('0' <= s[i] && s[i] <= '9')
		{
			result = result * base + (s[i] - '0');
		}
		else
		{
			result = result * base + (s[i] - 'A' + 10);
		}
	}
	cout << result << '\n';
	return 0;
}