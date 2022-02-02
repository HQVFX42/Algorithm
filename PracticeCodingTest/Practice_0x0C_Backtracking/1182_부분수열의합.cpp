// 2s, 256MB
// 1 <= N <= 20, |S| <= 1000000
#include <bits/stdc++.h>
using namespace std;

int n, s, cnt;
int arr[20];
// �� ���� ���� ������ ������ ������
void funcRecursive(int cur, int sum)
{
	if (cur == n)
	{
		if (sum == s)
		{
			cnt++;
		}
		return;
	}
	funcRecursive(cur + 1, sum);
	funcRecursive(cur + 1, sum + arr[cur]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	funcRecursive(0, 0);
	// ũ�Ⱑ ����� �κм��� �߿����̹Ƿ� �������϶��� ������Ѵ�
	if (s == 0)	
	{
		cnt--;
	}
	cout << cnt;
}