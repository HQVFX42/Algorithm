#include <iostream>

using namespace std;

int main()
{
	unsigned int num = 0;
	cin >> num;
	for (unsigned int i = 2; i*i <= num; i++)
	{
		while (num % i == 0)
		{
			cout << i << '\n';
			num = num / i;
		}
	}
	if (num != 1)
	{
		cout << num << '\n';
	}
	
	return 0;
}