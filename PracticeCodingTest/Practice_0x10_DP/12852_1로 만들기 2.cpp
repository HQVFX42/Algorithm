#include <bits/stdc++.h>
using namespace std;

int d[1111111], pre[1111111];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		d[i] = d[i - 1] + 1;
		pre[i] = i - 1;	// 최적 경로 저장
		if (i % 2 == 0 and d[i] > d[i / 2] + 1)
		{
			d[i] = d[i / 2] + 1;
			pre[i] = i / 2;	// 최적 경로 저장
		}
		if (i % 3 == 0 and d[i] > d[i / 3] + 1)
		{
			d[i] = d[i / 3] + 1;
			pre[i] = i / 3;	// 최적 경로 저장
		}
	}
	cout << d[n] << '\n';
	while (true)
	{	// 원소 순회를 이용한 경로 출력
		cout << n << ' ';
		if (n == 1) break;
		n = pre[n];
	}
}