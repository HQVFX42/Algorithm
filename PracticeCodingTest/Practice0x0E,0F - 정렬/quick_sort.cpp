#include <bits/stdc++.h>
using namespace std;

int n = 10;
int arr[1111];
// arr[st ~ en-1] ����
void qSort(int st, int en)
{
	if (en <= st + 1) return;	// base condition = ������ ���̰� 1 ���ϸ� ����
	int pivot = arr[st];
	int l = st + 1;
	int r = en - 1;
	while (true)
	{
		while (l <= r and arr[l] <= pivot) l++;
		while (r <= l and arr[r] >= pivot) r--;
		if (l < r) break;	// l�� r�� �����Ǵ� ���� Ż��
		swap(arr[l], arr[r]);
	}
	swap(arr[st], arr[r]);	// ������ �� pivot�� �������ָ� pivot�� ���ڸ��� ����
	qSort(st, r);
	qSort(r + 1, en);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	qSort(0, n);
	for (int i = 0; i < n; i++) cout << arr[i] << ' ';
}