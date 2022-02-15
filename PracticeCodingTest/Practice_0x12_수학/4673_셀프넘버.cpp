#include <bits/stdc++.h>
using namespace std;

const int MAX = 10001;
int arr[MAX];

int func(int n)
{
	int sum = n;
	while (n > 0)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int ans = 0;
	for (int i = 1; i < MAX; i++)
	{
		ans = func(i);
		if (ans <= MAX) arr[ans] = 1;
	}
	for (int i = 1; i < MAX; i++)
	{
		if (!arr[i]) cout << i << '\n';
	}
}