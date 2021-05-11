#include <iostream>

using namespace std;

int main()
{
	unsigned int n = 0;
	cin >> n;

	unsigned int result = 1;
	for (unsigned int i = 1; i <= n; i++)
	{
		result *= i;
	}
	cout << result << '\n';

	return 0;
}