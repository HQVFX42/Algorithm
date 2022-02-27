#include <bits/stdc++.h>
using namespace std;

int n;
string st;
vector<string> v;

bool cmp(string& a, string& b)
{
	int lena = a.size(), lenb = b.size();
	int suma = 0, sumb = 0;
	if (lena != lenb) return lena < lenb;

	for (int i = 0; i < lena; i++)
	{ // ���ڸ� ���Ѵ�. 
		if (isdigit(a[i])) suma += (a[i] - '0');
	}
	for (int i = 0; i < lenb; i++)
	{
		if (isdigit(b[i])) sumb += (b[i] - '0');
	}
	if (suma != sumb) return suma < sumb;
	return a < b; // ������
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> st;
		v.push_back(st);
	}
	sort(v.begin(), v.end(), cmp);
	for (auto i : v) cout << i << '\n';
}