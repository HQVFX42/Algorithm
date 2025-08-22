#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };
bool OOB(int x, int y, int n, int m) { return x < 0 or x >= n or y < 0 or y >= m; }
void FastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int main()
{
    FastIO();

    string s;

    cin >> s;

    int ToZero = 0, ToOne = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != s[i + 1])
        {
            if (s[i] == '0')
                ToOne++;
            else
                ToZero++;
        }
    }

    cout << min(ToZero, ToOne);

}