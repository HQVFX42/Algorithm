#include <bits/stdc++.h>
using namespace std;

int n = 10;
int arr[1111];
// arr[st ~ en-1] 정렬
void qSort(int st, int en)
{
	if (en <= st + 1) return;	// base condition = 수열의 길이가 1 이하면 종료
	int pivot = arr[st];
	int l = st + 1;
	int r = en - 1;
	while (true)
	{
		while (l <= r and arr[l] <= pivot) l++;
		while (r <= l and arr[r] >= pivot) r--;
		if (l < r) break;	// l과 r이 역전되는 순간 탈출
		swap(arr[l], arr[r]);
	}
	swap(arr[st], arr[r]);	// 역전된 후 pivot을 스왑해주면 pivot이 제자리로 간다
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