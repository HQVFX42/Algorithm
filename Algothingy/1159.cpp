//
//  1159.cpp
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

int cnt[26];
int main()
{
    int tc;
    cin >> tc;
    while (tc--) {
        string s;
        cin >> s;
        
        cnt[s[0] - 'a']++;
    }
    
    string result = "";
    for (int i = 0; i < sizeof(cnt) / sizeof(*cnt); i++) {
        if (cnt[i] >= 5) {
            result += i + 'a';
        }
    }
    
    if (result.size()) {
        cout << result;
    }
    else
    {
        cout << "PREDAJA";
    }
}
