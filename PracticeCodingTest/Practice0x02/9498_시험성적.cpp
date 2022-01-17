#include <iostream>
using namespace std;

void grade(int n)
{
	int n;
	cin >> n;
	if (n >= 90) cout << 'A';
	else if (n >= 80) cout << 'B';
	else if (n >= 70) cout << 'C';
	else if (n >= 60) cout << 'D';
	else cout << 'F';
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int testScore;
	cin >> testScore;
	if (testScore >= 90 && testScore <=100)
	{
		cout << 'A';
	}
	else if (testScore >= 80 && testScore <= 89)
	{
		cout << 'B';
	}
	else if (testScore >= 70 && testScore <= 79)
	{
		cout << 'C';
	}
	else if (testScore >= 60 && testScore <= 69)
	{
		cout << 'D';
	}
	else
	{
		cout << 'F';
	}
}