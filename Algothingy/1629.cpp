#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

void fastIO()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
}

ll a, b, c;
ll go(ll a, ll b)
{
	if (b == 1)
	{
		return a % c;
	}

	ll ans = go(a, b / 2);
	ans = (ans * ans) % c;

	if (b & 1)
	{
		ans = (ans * a) % c;
	}

	return ans;
}

int main()
{
	fastIO();

	cin >> a >> b >> c;
	cout << go(a, b);
}