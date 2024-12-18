//
//  11655.cpp
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
    getline(cin, s);
    
    for (int i = 0; i < s.size(); i++) {
        int start = 'A';
        int end = 'Z';
        int diff = 13;
        if (s[i] >= start and s[i] <= end) {
            if (s[i] + diff <= end) {
                s[i] += diff;
            }
            else {
                s[i] -= diff;
                
            }
        }
        else
        {
            start = 'a';
            end = 'z';
            if (s[i] >= start and s[i] <= end) {
                if (s[i] + diff <= end) {
                    s[i] += diff;
                }
                else {
                    s[i] -= diff;
                }
            }
        }
        
    }
    cout << s;
}
