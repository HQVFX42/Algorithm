#include <iostream>

using namespace std;

int TIME = 3;
int result, input;
string strResult = "DCBAE";

int main()
{

	while (TIME--)
	{
		result = 0;
		for (int i = 0; i < 4; i++)
		{
			cin >> input;
			result += input;
		}
		cout << strResult[result] << '\n';
	}
}