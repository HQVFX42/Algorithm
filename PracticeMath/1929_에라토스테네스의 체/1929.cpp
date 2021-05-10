#include <iostream>

using namespace std;

const int MAX = 1000000;
bool check[MAX + 1];

int main()
{
	//에라토스테네스의 체
	check[0] = check[1] = true;		//0과 1은 제외
	for (int i = 2; i <= MAX; i++)
	{
		if (check[i] == false)
		{
			for (int j = i + i; j < MAX; j = j + i)
			{
				check[j] = true;
			}
		}
	}

	unsigned int m, n;
	cin >> m >> n;
	for (int i = m; i <= n; i++)
	{
		if (check[i] == false)
		{
			cout << i << '\n';
		}
	}
	return 0;
}