#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int TC;
	cin >> TC;

	int time[10000], Y = 0, M = 0;
	for (int i = 0; i < TC; i++)
	{
		cin >> time[i];		
	}

	for (int i = 0; i < TC; i++)
	{
		Y += ((time[i] / 30) + 1) * 10;
	}

	for (int i = 0; i < TC; i++)
	{
		M += ((time[i] / 60) + 1) * 15;
	}

	if (Y < M)
	{
		cout << "Y " << Y;
	}
	else if (Y > M)
	{
		cout << "M " << M;
	}
	else
	{
		cout << "Y M " << Y;
	}
}