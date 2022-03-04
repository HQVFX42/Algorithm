#include <bits/stdc++.h>
using namespace std;

int d[1111];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	d[1] = 1;
	d[2] = 2;
	for (int i = 3; i <= n; i++)
	{	// 마지막에만 나머지 연산으로 출력하게 되면 int 오버플로우가 날 수 있다
		d[i] = (d[i - 1] + d[i - 2]) % 10007;
	}
	cout << d[n];
}