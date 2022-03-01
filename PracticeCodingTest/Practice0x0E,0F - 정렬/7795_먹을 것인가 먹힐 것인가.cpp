#include <bits/stdc++.h>
using namespace std;
// ���� Ž��
void solution1()
{
	int TC;
	cin >> TC;
	while (TC--)
	{
		int n, m;
		cin >> n >> m;
		vector<pair<int, int>> v(n + m);
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			v[i] = { a,0 };
		}
		for (int i = n; i < n + m; i++)
		{
			int b;
			cin >> b;
			v[i] = { b,1 };
		}
		sort(v.begin(), v.end());
		int cnt = 0;	// ������� ���� b�� ����
		int ans = 0;
		for (int i = 0; i < n + m; i++)
		{
			if (v[i].second == 0) ans += cnt;	// A����
			else cnt++;	// B����
		}
		cout << ans << '\n';
	}
}
// �̺� Ž��
void solution2()
{
	int TC;
	cin >> TC;
	while (TC--)
	{
		int n, m;
		cin >> n >> m;
		vector<int> v(n);
		for (int i = 0; i < n; i++) cin >> v[i];
		sort(v.begin(), v.end());
		int ans = 0;
		for (int i = 0; i < m; i++)
		{
			int b;
			cin >> b;
			// b���� ū ���ڰ� �迭(A����)���� ó�� �����ϴ� ��ġ
			int index = upper_bound(v.begin(), v.end(), b) - v.begin();
			ans += n - index;
		}
		cout << ans << '\n';
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	//solution1();
	solution2();
}