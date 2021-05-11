#include <iostream>

using namespace std;

int main()
{
	unsigned int n;
	cin >> n;

	unsigned int result = 0;

	for (unsigned int i = 5; i <= n; i *= 5)
	{
		result += n / i;
	}
	cout << result << '\n';

	return 0;
}