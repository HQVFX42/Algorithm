#include <bits/stdc++.h>
using namespace std;

void print()
{
	int a[7];
	vector<int> v;
	int ans = 0;
	for (int i = 0; i < 7; i++)
	{
		cin >> a[i];
		if (a[i] & 1)
		{
			v.push_back(a[i]);
		}
	}
	sort(v.begin(), v.end());
	for (auto i : v)
	{
		ans += i;
	}
	if (!v.empty())	cout << ans << '\n' << v[0];
	else cout << -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int x, odd = 0, sum = 0, min = 100;

	for (int i = 0; i < 7; i++)
	{
		cin >> x;

		if (x % 2 == 1)
		{
			odd += 1;
			sum += x;

			if (x < min)
			{
				min = x;
			}
		}
	}

	if (odd)
	{
		cout << sum << "\n" << min;
	}
	else
	{
		cout << "-1";
	}

}