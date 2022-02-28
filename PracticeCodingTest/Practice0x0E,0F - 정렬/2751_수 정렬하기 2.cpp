#include <bits/stdc++.h>
using namespace std;

int n, arr[1111111], tmp[1111111];

void myMerge(int st, int en)
{
	int mid = (st + en) / 2;
	int l = st, r = mid;
	for (int i = st; i < en; i++)
	{
		if (r == en) tmp[i] = arr[l++];
		else if (l == mid) tmp[i] = arr[r++];
		else if (arr[l] <= arr[r]) tmp[i] = arr[l++];
		else if (arr[r] < arr[l]) tmp[i] = arr[r++];
	}
	for (int i = st; i < en; i++) arr[i] = tmp[i];
}

void mergeSort(int st, int en)
{
	if (st + 1 == en) return;
	int mid = (st + en) / 2;
	mergeSort(st, mid);
	mergeSort(mid, en);
	myMerge(st, en);
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