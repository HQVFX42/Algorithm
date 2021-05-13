#include <iostream>

using namespace std;

// 재귀함수를 이용한 10진수 -> 2진수
//void toBinary(int num)
//{
//	if (num == 0 || num == 1)
//	{
//		cout << num;
//	}
//	else
//	{
//		toBinary(num / 2);
//		cout << num % 2;
//	}
//}

void toBinary(int n)
{
	if (n == 0) { return; }
	if (n % 2 == 0)
	{
		toBinary(-(n / 2));
		cout << 0;
	}
	else
	{
		if (n > 0) { toBinary(-(n / 2)); }
		else { toBinary((-n + 1) / 2); }
		cout << 1;
	}
}

int main()
{
	int n = 0;
	cin >> n;
	if (n == 0) cout << 0;
	else toBinary(n);

	return 0;
}