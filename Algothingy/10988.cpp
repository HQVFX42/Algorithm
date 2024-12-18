//
//  10988.cpp
//  Algothingy
//
//  Created by carroll on 12/7/23.
//

#include <bits/stdc++.h>

using namespace std;

void fastIO()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
}

int main()
{
    string s;
    cin >> s;
    string temp;
    temp = s;
    reverse(temp.begin(), temp.end());
    
    if (s == temp) {
        cout << 1;
    }
    else {
        cout << 0;
    }
}
