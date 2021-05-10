#include <iostream>

using namespace std;

const int MAX = 1000000;
int prime[MAX];
int pn;
bool isChecked[MAX + 1];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	isChecked[0] = isChecked[1] = true;
	for (int i = 2; i <= MAX; i++)
	{
		if (isChecked[i] == false)
		{
			prime[pn++] = i;
			for (int j = i + i; j <= MAX; j = j + i)
			{
				isChecked[j] = true;
			}
		}
	}

	while (true)
	{
		int n;
		cin >> n;
		if (n == 0) { break; }

		int a = 0, b = 0;
		bool isCorrect = false;
		for (int i = 1; i < pn; i++)
		{
			if (isChecked[n - prime[i]] == false)
			{
				a = prime[i];
				b = n - prime[i];
				isCorrect = true;
				
				break;
			}
		}
		if (isCorrect)
		{
			cout << n << " = " << a << " + " << b << '\n';
		}
		else
		{
			cout << "Goldbach's conjecture is wrong." << '\n';
			break;
		}
	}
	return 0;
}