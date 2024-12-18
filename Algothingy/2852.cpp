#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
bool OOB(int x, int y, int n, int m) { return x < 0 or x >= n or y < 0 or y >= m; }
void FastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

string ChangeToString(int N)
{
	string Minutes = "00" + to_string(N / 60);
	string Seconds = "00" + to_string(N % 60);
	return Minutes.substr(Minutes.size() - 2, 2) + ':' + Seconds.substr(Seconds.size() - 2, 2);
}

int ChangeToInt(string S)
{
	return atoi(S.substr(0, 2).c_str()) * 60 + atoi(S.substr(3, 2).c_str());
}

string Prev;
void Func(int & Sum, string S)
{
	Sum += ChangeToInt(S) - ChangeToInt(Prev);
}

int main()
{
	FastIO();

	int N = 0;
	cin >> N;

	int TeamA = 0;
	int TeamB = 0;
	int SumA = 0;
	int SumB = 0;
	while (N--)
	{
		int TeamNumber = 0;
		string S = "";
		cin >> TeamNumber >> S;
		if (TeamA > TeamB)
		{
			Func(SumA, S);
		}
		else if (TeamB > TeamA)
		{
			Func(SumB, S);
		}
		TeamNumber == 1 ? TeamA++ : TeamB++;
		Prev = S;
	}

	if (TeamA > TeamB)
	{
		Func(SumA, "48:00");
	}
	else if (TeamB > TeamA)
	{
		Func(SumB, "48:00");
	}

	cout << ChangeToString(SumA) << '\n';
	cout << ChangeToString(SumB) << '\n';
}