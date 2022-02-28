#include <bits/stdc++.h>
using namespace std;

int n, arr[1111], tmp[1111];
// 두 배열의 맨 앞 인덱스끼리 값을 비교하며 더 작은 값을 순서대로 집어넣어 정렬
void mergeArray(int st, int en)
{
	int mid = (st + en) / 2;
	int l = st, r = mid;
	for (int i = st; i < en; i++)
	{
		if (r == en) tmp[i] = arr[l++];	// index r이 끝에 도달했을 때
		else if (l == mid) tmp[i] = arr[r++];	// inderx l이 끝에 도달했을 때
		else if (arr[l] <= arr[r]) tmp[i] = arr[l++];	// ** l = r : stable sort **
		else tmp[i] = arr[r++];
	}
	for (int i = st; i < en; i++) arr[i] = tmp[i];
}
void mergeSort(int st, int en)
{
	if (en == st + 1) return;	// 길이가 1인 경우
	int mid = (st + en) / 2;
	mergeSort(st, mid);	// st ~ mid-1
	mergeSort(mid, en);	// mid ~ en-1
	mergeArray(st, en);	// st ~ mid, mid ~ en을 합친다
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