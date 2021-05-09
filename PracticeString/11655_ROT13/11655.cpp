#include <iostream>
#include <string>
using namespace std;

//string rot13(string s)
//{
//	for (int x = 0; x < s.size(); x++)
//	{
//		if ('a' <= s[x] && s[x] <= 'm')
//		{
//			s[x] = s[x] + 13;
//		}
//		else if ('n' <= s[x] && s[x] <= 'z')
//		{
//			s[x] = s[x] - 13;
//		}
//		else if ('A' <= s[x] && s[x] <= 'M')
//		{
//			s[x] = s[x] + 13;
//		}
//		else if ('N' <= s[x] && s[x] <= 'Z')
//		{
//			s[x] = s[x] - 13;
//		}
//	}
//	return s;
//}

int main()
{
	/*string s;
	getline(cin, s);
	cout << rot13(s);*/
	
	string s;
	while (getline(cin, s))
	{
		for (int i = 0; i < s.size(); i++)
		{
			if ('a' <= s[i] && s[i] <= 'm')			//소문자는 소문자대로
			{
				s[i] += 13;
			}
			else if ('n' <= s[i] && s[i] <= 'z')
			{
				s[i] -= 13;
			}
			else if ('A' <= s[i] && s[i] <= 'M')	//대문자는 대문자대로
			{
				s[i] += 13;
			}
			else if ('N' <= s[i] && s[i] <= 'Z')
			{
				s[i] -= 13;
			}
		}
	cout << s << '\n';
	}
	return 0;
}