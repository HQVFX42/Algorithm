#include <bits/stdc++.h>
using namespace std;
// 2���� �迭 Ǯ��
void sol1()
{
	int d[333][3] = {};
	int score[333] = {};
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> score[i];
	}
	// d[i][1] ������� 1���� ����� �����ؼ� ��� i���� �ö� ���� �� ���� ���� �ִ�
	// d[i][2] ������� 2���� ����� �����ؼ� ��� i���� �ö� ���� �� ���� ���� �ִ�
	d[1][1] = score[1];
	d[1][2] = 0;
	d[2][1] = score[2];
	d[2][2] = score[1] + score[2];
	for (int i = 3; i <= n; i++)
	{
		d[i][1] = max(d[i - 2][1], d[i - 2][2]) + score[i];
		d[i][2] = d[i - 1][1] + score[i];
	}

	int ans = 0;
	ans = max(d[n][1], d[n][2]);
	cout << ans;
}
// 1���� �迭 Ǯ��
void sol2()
{

}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	//sol1();
	sol2();
}