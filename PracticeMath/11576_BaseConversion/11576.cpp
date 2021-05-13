#include <iostream>

using namespace std;

void toChange(unsigned int num, unsigned int base)
{
	if (num == 0) { return; }
	else { toChange(num / base, base); }
	cout << (num % base) << " ";
}

int main()
{
	unsigned int baseA = 0, baseB = 0;
	cin >> baseA >> baseB;

	unsigned int size = 0;
	cin >> size;

	unsigned int result = 0;
	for (unsigned int i = 0; i < size; i++)
	{
		unsigned int inputNum;
		cin >> inputNum;
		result = result * baseA + inputNum;
	}
	toChange(result, baseB);

	return 0;
}