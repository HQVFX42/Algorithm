#include <iostream>

using namespace std;

unsigned int gcd(unsigned int a, unsigned int b)
{
	if (b == 0) { return a; }
	else { return gcd(b, a % b); }
}

int main()
{
	unsigned int testCase = 0;
	cin >> testCase;

	while (testCase--)
	{
		int result[100];
		unsigned int num = 0;
		cin >> num;
		unsigned int sum = 0;
		for (unsigned int i = 0; i < num; i++)
		{
			cin >> result[i];
		}
		//�ߺ��� GCD���� ��� ó���ұ�...? -->> �ݺ��� ���� �߿�**** �迭���� i~num-1, j=i+1~num
		for (unsigned int i = 0; i < num - 1; i++)
		{
			for (unsigned int j = i + 1; j < num; j++)
			{
				sum += gcd(result[i], result[j]);
			}
		}
		cout << sum << '\n';
	}

	return 0;
}