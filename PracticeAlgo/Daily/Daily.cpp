#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef pair<int, int> pii;

const int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
bool OOB(int x, int y, int n, int m) { return x < 0 or x >= n or y < 0 or y >= m; }
void fastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

const int MAX = 1111;
int graph[MAX][MAX];
int vis[MAX][MAX];
string a[MAX];

bool isVowel(char idx)
{
	return (idx == 'a' or idx == 'e' or idx == 'i' or idx == 'o' or idx == 'u');
}
void print(string s, bool pass)
{
	if (!pass)
	{
		cout << "<" << s << ">" << "is not acceptable.\n";
	}
	else
	{
		cout << "<" << s << ">" << "is acceptable.\n";
	}
}
int main()
{
	string vowel = "aeiou";
	while (true)
	{
		string s;
		cin >> s;
		if (s == "end")
		{
			break;
		}
		int conN = 0;
		int vowN = 0;
		bool duo = false;
		bool trio = false;
		bool includeV = false;
		char prev;

		for (int i = 0; i < s.length(); i++)
		{
			if (isVowel(s[i]))
			{
				vowN++;
				conN = 0;
				includeV = true;
			}
			else
			{
				vowN = 0;
				conN++;
			}
			if (vowN >= 3 or conN >= 3)
			{
				trio = true;
			}
			if (i >= 1 and prev == s[i] and s[i] != 'e' and s[i] != 'o')
			{
				duo = true;
			}
			prev = s[i];
		}

		if (!includeV or duo or trio)
		{
			print(s, false);
		}
		else
		{
			print(s, true);
		}
	}
}