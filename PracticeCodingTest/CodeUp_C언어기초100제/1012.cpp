#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	float f;
	cin >> f;
	cout.setf(ios::showpoint);	// 소수점 표시 및 생략된 0 모두 출력
	cout.precision(7);			// 출력할 전체 자리수
	cout << f;
}