#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	while (getline(cin, s))		//�����Ŀ��� ���ڿ��� ��� �Է� �ޱ� ����							
	{
		int lower = 0, upper = 0, number = 0, space = 0;

		for (auto x : s)
		{
			if ('a' <= x && x <= 'z')
			{
				lower++;
			}
			else if ('A' <= x && x <= 'Z')
			{
				upper++;
			}
			else if ('0' <= x && x <= '9')
			{
				number++;
			}
			else if (x == ' ')
			{
				space++;
			}
		}
		cout << lower << ' ' << upper << ' ' << number << ' ' << space << '\n';
	}
}