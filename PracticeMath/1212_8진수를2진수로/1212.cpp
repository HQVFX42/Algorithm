#include <iostream>
#include <string>
using namespace std;

string eight[8] = { "000", "001", "010", "011", "100", "101", "110" , "111" };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string s;
	cin >> s;
	if (s.length() == 1 && s[0] - '0' == 0)
	{
		cout << "0";
	}
	bool isFront = true;
	for (unsigned int i = 0; i < s.size(); i++)
	{
		unsigned int n = s[i] - '0';
		if (isFront == true && n < 4)
		{
			if (n == 0)
			{
				continue;
			}
			else if (n == 1)
			{
				cout << "1";
			}
			else if (n == 2)
			{
				cout << "10";
			}
			else if (n == 3)
			{
				cout << "11";
			}
			isFront = false;
		}
		else
		{
			cout << eight[n];
			isFront = false;
		}
	}

	return 0;
}