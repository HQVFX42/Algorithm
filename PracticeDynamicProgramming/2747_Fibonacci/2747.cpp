#include <iostream>

using namespace std;

// Top-down 방식( 재귀 )
//int memo[100];
//unsigned int fibonacci(unsigned int n)
//{
//	if (n <= 1)
//	{
//		return n;
//	}
//	else
//	{
//		if (memo[n] > 0)
//		{
//			return memo[n];
//		}
//		memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
//		return memo[n];
//	}
//}

// Bottom-up ( 반복문 )
int memo[100];
int fibonacci(int n)
{
	memo[0] = 0;
	memo[1] = 1;
	for (unsigned int i = 2; i <= n; i++)
	{
		memo[i] = memo[i - 1] + memo[i - 2];
	}
	return memo[n];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	unsigned int n;
	cin >> n;
	cout << fibonacci(n) << '\n';

	return 0;
}