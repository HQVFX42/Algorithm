#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
bool OOB(int x, int y, int n, int m) { return x < 0 or x >= n or y < 0 or y >= m; }
void FastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

string S;
int A[ 111 ][ 111 ];

int main()
{
	FastIO();

	int H = 0;
	int W = 0;
	cin >> H >> W;

	for (int i = 0; i < H; i++)
	{
		cin >> S;
		for (int j = 0; j < W; j++)
		{
			if (S[j] == '.')
			{
				A[ i ][ j ] = -1;
			}
			else
			{
				A[ i ][ j ] = 0;
			}
		}
	}

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (A[i][j] == 0)
			{
				int Cnt = 1;
				while (A[i][j+1] == - 1)
				{
					A[ i ][ j + 1 ] = Cnt++;
					j++;
				}
			}
		}
	}

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cout << A[ i ][ j ] << ' ';
		}
		cout << '\n';
	}
}