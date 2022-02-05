// 1s, 512MB
// 1 <= M <= 8
#include <bits/stdc++.h>
using namespace std;

int arr[10];
bool bUsed[10];

void funcRecursive(int k, int n, int m)	// ���� k���� ���� �����ߴ�
{
	if (k == m)	// m���� ��� ��������
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << ' ';	// arr�� ����ص� ���� ���
		}
		cout << '\n';
		return;
	}
	int cnt = arr[k - 1] + 1;
	//int cnt = 1;	// ��������, k = 0�� ���� 1
	//if(cnt != 0) cnt = arr[k - 1] + 1;	// k != 0�� ��� arr[k-1] + 1
	for (int i = cnt; i <= n; i++)
	{
		if (bUsed[i] == false)	// ���� i�� ������ �ʾ�����
		{
			arr[k] = i;	// k��° ���� i�� ���Ѵ�
			bUsed[i] = true;	// i�� ���
			funcRecursive(k + 1, n, m);	// ���� ���� ���Ϸ� �� �ܰ� ��
			bUsed[i] = false;	// k��° ���� i�� ���� ��� ��쿡 ���� �� Ȯ�������� i�� �̻��
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;
	funcRecursive(0, N, M);
}