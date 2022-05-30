#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

ll power(ll a, ll b, ll c)
{
	if (b == 1)
	{	// base condition
		return a % c;
	}

	ll ans = power(a, b * 0.5, c);
	ans = (ans * ans) % c;
	if (b & 1)
	{
		return ans * a % c;
	}
	else
	{
		return ans;
	}
}

int main()
{
	fastIO();
	ll a, b, c;
	cin >> a >> b >> c;
	cout<< power(a, b, c);
}