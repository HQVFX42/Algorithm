//
//  9996.cpp
//  Algothingy
//
//  Created by carroll on 12/8/23.
//

#include <bits/stdc++.h>

using namespace std;

void fastIO()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
}

int main()
{
    int tc = 0;
    cin >> tc;
    
    string pattern = "";
    cin >> pattern;
    
    unsigned long pos = pattern.find("*");
    string prefix = pattern.substr(0, pos);
    string suffix = pattern.substr(pos + 1);
    
    while (tc--) 
    {
        string s;
        cin >> s;
        if (s.size() < prefix.size() + suffix.size())
        {
            cout << "NE" << "\n";
        }
        else
        {
            if (s.substr(0, prefix.size()) == prefix && s.substr(s.size() - suffix.size()) == suffix)
            {
                cout << "DA" << "\n";
            }
            else
            {
                cout << "NE" << "\n";
            }
        }
    }
}
