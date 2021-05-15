#include <iostream>

using namespace std;


int operate(int n)
{
	unsigned int result = 0;
	if (n % 3 == 0)
	{
		n = n / 3;
	}
	else if (n % 2 == 0)
	{
		n = n / 3;
	}
	else
	{
		n-1;
	}
}

int main()
{

	return 0;
}