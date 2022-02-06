// 1s, 512MB
// 1 <= M <= N <= 8
#include <bits/stdc++.h>
using namespace std;

int arr[10];
bool bUsed[10];
int num[10];

void funcRecursive(int k, int n, int m)	// ���� k������ ���� �����ߴ�
{
	if (k == m)	// m���� ��� ���ߴٸ�
	{
		for (int i = 0; i < m; i++)
		{
			cout << num[arr[i]] << ' ';	// arr�� ����ص� �ε����� �����Ǵ� �� ���
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++)	// 0 ���� n-1������ �ε����� ����
	{
		if (bUsed[i] == false)	// ���� i�� ������ �ʾ�����
		{
			arr[k] = i;	// k��° �ε����� i�� ����
			bUsed[i] = true;	// i ���
			funcRecursive(k + 1, n, m);	// ���� �ε��� ���Ϸ� �� �ܰ� �� ����
			bUsed[i] = false;	// k��° �ε����� i�� ���� ��� ��쿡 ���� �� Ȯ�������� i �̻������ ��ȯ
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	sort(num, num + n);
	funcRecursive(0, n, m);
}