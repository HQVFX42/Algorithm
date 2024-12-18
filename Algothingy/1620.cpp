//
//  1620.cpp
//  Algothingy
//
//  Created by carroll on 12/14/23.
//

#include <bits/stdc++.h>

using namespace std;

void fastIO()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
}

int main()
{
    fastIO();
    
    int n;
    int m;
    cin >> n >> m;
    
    map<int, string> m1;
    map<string, int> m2;
    for (int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        m1[i + 1] = tmp;
        m2[tmp] = i + 1;
    }
    
    for (int i = 0 ; i < m; i++)
    {
        string tmp;
        cin >> tmp;
        if (atoi(tmp.c_str()))
        {
            cout << m1[atoi(tmp.c_str())] << "\n";
        }
        else
        {
            cout << m2[tmp] << "\n";
        }
    }
}
