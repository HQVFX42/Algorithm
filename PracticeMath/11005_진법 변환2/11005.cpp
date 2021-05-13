#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	unsigned int n = 0;
	unsigned int base = 0;
	cin >> n >> base;
	string result = "";
	while (n > 0)
	{
		int r = n % base;
		if (r < 10) { result += r + '0'; }
		else { result += r - 10 + 'A'; }
		n /= base;
	}
	reverse(result.begin(), result.end());
	cout << result << '\n';

	return 0;
}