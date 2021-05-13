#include <iostream>

using namespace std;

const unsigned int MAX = 1000000;
unsigned int prime[MAX];
unsigned int pn;
bool isChecked[MAX + 1];

int main()
{
	isChecked[0] = isChecked[1] = true;
	for (unsigned int i = 2; i <= MAX; i++)
	{
		if (isChecked[i] == false)
		{
			prime[pn++] = i;
			for (unsigned int j = i + i; j <= MAX; j += i)
			{
				isChecked[j] = true;
			}
		}
	}

	unsigned int testCase = 0;
	cin >> testCase;
	while (testCase--)
	{
		unsigned int n = 0;
		cin >> n;
		unsigned int result = 0;
		for (unsigned int i = 0; i < pn; i++)
		{
			if (2 <= n-prime[i] && n-prime[i] >= prime[i])
			{
				if (isChecked[n - prime[i]] == false)
				{
					result++;
				}
			}
			else { break; }
		}
		cout << result << '\n';
	}

	return 0;
}