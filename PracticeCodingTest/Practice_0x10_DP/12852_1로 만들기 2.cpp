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
		pre[i] = i - 1;	// ���� ��� ����
		if (i % 2 == 0 and d[i] > d[i / 2] + 1)
		{
			d[i] = d[i / 2] + 1;
			pre[i] = i / 2;	// ���� ��� ����
		}
		if (i % 3 == 0 and d[i] > d[i / 3] + 1)
		{
			d[i] = d[i / 3] + 1;
			pre[i] = i / 3;	// ���� ��� ����
		}
	}
	cout << d[n] << '\n';
	while (true)
	{	// ���� ��ȸ�� �̿��� ��� ���
		cout << n << ' ';
		if (n == 1) break;
		n = pre[n];
	}
}