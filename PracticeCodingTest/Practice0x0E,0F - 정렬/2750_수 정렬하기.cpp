#include <bits/stdc++.h>
using namespace std;

int n, arr[1111], tmp[1111];
// �� �迭�� �� �� �ε������� ���� ���ϸ� �� ���� ���� ������� ����־� ����
void mergeArray(int st, int en)
{
	int mid = (st + en) / 2;
	int l = st, r = mid;
	for (int i = st; i < en; i++)
	{
		if (r == en) tmp[i] = arr[l++];	// index r�� ���� �������� ��
		else if (l == mid) tmp[i] = arr[r++];	// inderx l�� ���� �������� ��
		else if (arr[l] <= arr[r]) tmp[i] = arr[l++];	// ** l = r : stable sort **
		else tmp[i] = arr[r++];
	}
	for (int i = st; i < en; i++) arr[i] = tmp[i];
}
void mergeSort(int st, int en)
{
	if (en == st + 1) return;	// ���̰� 1�� ���
	int mid = (st + en) / 2;
	mergeSort(st, mid);	// st ~ mid-1
	mergeSort(mid, en);	// mid ~ en-1
	mergeArray(st, en);	// st ~ mid, mid ~ en�� ��ģ��
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	mergeSort(0, n);
	for (int i = 0; i < n; i++) cout << arr[i] << '\n';
}