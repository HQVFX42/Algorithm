#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> answer;
	vector<int> v;
	answer = { 13, 15, 14, 17, 19, 18, 22, -1, -4 };
	int d = 3, k = 2;
	int count = 0;

	for (auto i = 1; i < answer.size() - 1; i++)
	{
		if (abs(answer[i] - answer[i + 1]) <= d && count <= k)
		{
			answer.erase(answer.begin() + i);
			i--;
			count++;

		}
		else
		{
			count = 0;
		}
	}	

	cout << "\n";
	for (auto i = answer.begin(); i != answer.end(); i++)
	{
		cout << *i << " ";
	}
	
}