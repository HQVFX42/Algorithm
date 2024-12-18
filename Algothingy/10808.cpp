//
//  10808.cpp
//  Algothingy
//
//  Created by carroll on 12/6/23.
//

/* 10808 알파벳 개수 https://www.acmicpc.net/problem/10808 */
#include <bits/stdc++.h>

using namespace std;

int cnt[26];

int main()
{
    string s;
    cin >> s;
    
    for (auto c : s) {
        cnt[c - 'a']++;
    }
    
    for (int i = 0; i < 26; i++)
    {
        cout << cnt[i] << ' ';
    }
}
