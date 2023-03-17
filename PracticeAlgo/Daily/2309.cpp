#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
bool OOB(int x, int y, int n, int m) { return x < 0 or x >= n or y < 0 or y >= m; }
void fastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int a[111];
int sum;
pii ret;

void permuation(int n, int r, int depth)
{
	if (depth == r)
	{
		int sum1 = 0;
		for (int i = 0; i < r; i++)
		{
			sum1 += a[i];
		}
		if (sum1 == 100)
		{
			sort(a, a + 7);
			for (int i = 0; i < r; i++)
			{
				cout << a[i] << "\n";
			}
			exit(0);
		}
		for (int i = 0; i < r; i++)
		{
			//cout << a[i] << " ";
		}
		//cout << "\n";
		return;
	}
	for (int i = depth; i < n; i++)
	{
		swap(a[i], a[depth]);
		permuation(n, r, depth + 1);
		swap(a[i], a[depth]);
	}
}

int main()
{
	fastIO();
	for (int i = 0; i < 9; i++)
	{
		cin >> a[i];
		//sum += a[i];
	}

	//for (int i = 0; i < 9; i++)
	//{
	//	for (int j = 0; j < i; j++)
	//	{
	//		if (sum - a[i] - a[j] == 100)
	//		{
	//			ret = { i,j };
	//			break;
	//		}
	//	}
	//}

	//vector<int> v;
	//for (int i = 0; i < 9; i++)
	//{
	//	if (ret.first == i || ret.second == i)
	//	{
	//		continue;
	//	}
	//	v.push_back(a[i]);
	//}
	//sort(v.begin(), v.end());
	//for (auto& i : v)
	//{
	//	cout << i << " ";
	//}
	permuation(9, 7, 0);
}