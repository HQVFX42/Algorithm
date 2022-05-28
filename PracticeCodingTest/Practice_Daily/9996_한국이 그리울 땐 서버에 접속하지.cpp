#include <bits/stdc++.h>
using namespace std;

void fastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int cnt[26];

int main()
{
	fastIO();
	int n;
	cin >> n;
	string s;
	cin >> s;
	int pos = s.find('*');
	string prefix, sufix;
	prefix = s.substr(0, pos);
	sufix = s.substr(pos + 1);
	
	for (int i = 0; i < n; i++)
	{
		string tmp;
		cin >> tmp;
		int tsz = tmp.size(), psz = prefix.size(), ssz = sufix.size();
		if (psz + ssz > tsz)
		{
			cout << "NE\n";
		}
		else
		{
			if (prefix == tmp.substr(0, psz) and sufix == tmp.substr(tsz - ssz))
			{
				cout << "DA\n";
			}
			else
			{
				cout << "NE\n";
			}
		}
	}
}