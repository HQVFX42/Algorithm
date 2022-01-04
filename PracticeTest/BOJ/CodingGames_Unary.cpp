#include <bits/stdc++.h>
using namespace std;

string toBinary(int n)
{
	string r;
	while (n != 0) {
		r += (n % 2 == 0 ? "0" : "1");
		n /= 2;
	}
	return r;
}

int main()
{
	string message;
	getline(cin, message);

	vector<string> answer;
	vector<char> v;
	string s;
	string sB;
	for (int i = 0; i < message.size(); i++)
	{
		s = toBinary((int)message[i]);
		if (s.length() < 7)
		{
			s += "0";			
		}
		reverse(s.begin(), s.end());
		sB = sB + s;
	}

	for (char c : sB)
	{
		v.push_back(c);
	}

	int count = 1;
	for (int i = 0; i < v.size(); i++)
	{
		if (i + 1 < v.size() && v[i] == v[i + 1])
		{
			count++;
		}
		if (i + 1 == v.size() || v[i] != v[i + 1])
		{
			if (v[i] == '1') answer.push_back("0 ");
			else if (v[i] == '0') answer.push_back("00 ");

			for (int j = 0; j < count; j++) answer.push_back("0");
			if (i != v.size() - 1) answer.push_back(" ");
			count = 1;
		}
	}

	cout << sB << endl;
	for (int i = 0; i < answer.size(); i++) cout << answer[i];
	cout << endl;
}