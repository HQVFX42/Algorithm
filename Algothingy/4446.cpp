//
//  4446.cpp
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

string s;
string vowel;
string consonant;

void Rot(int index, bool bIsUpper)
{
    string result = "";
    
    if (bIsUpper) {
        vowel = "AIYEOU";
        consonant = "BKXZNHDCWGPVJQTSRLMF";
    }
    else
    {
        vowel = "aiyeou";
        consonant = "bkxznhdcwgpvjqtsrlmf";
    }
    int diff = 0;
    
    for (int j = 0; j < vowel.size(); j++) {
        if (s[index] == vowel[j]) {
            diff = 3;
            if (j + diff < vowel.size()) {
                s[index] = vowel[j + diff];
                return;
            }
            else
            {
                s[index] = vowel[j - diff];
                return;
            }
        }
    }
    
    for (int j = 0; j < consonant.size(); j++) {
        if (s[index] == consonant[j]) {
            diff = 10;
            if (j + diff < consonant.size()) {
                s[index] = consonant[j + diff];
                return;
            }
            else
            {
                s[index] = consonant[j - diff];
                return;
            }
        }
    }
}

int main()
{
    while (getline(cin, s))
    {
        for (int i = 0; i < s.size(); i++) {
            int start = 'A';
            int end = 'Z';
            if (s[i] >= start and s[i] <= end) {
                Rot(i, true);
            }
            else
            {
                start = 'a';
                end = 'z';
                Rot(i, false);
            }
            
        }
        cout << s << "\n";
    }
}

