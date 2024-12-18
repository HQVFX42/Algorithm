//
//  main.cpp
//  Algothingy
//
//  Created by carroll on 12/3/23.
//

#include <bits/stdc++.h>

using namespace std;

void fastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

vector<string> Split(string input, string delimeter)
{
    vector<string> result;

    string token = "";
    unsigned long pos = 0;
    while ((pos = input.find(delimeter)) != string::npos)
    {
        token = input.substr(0, pos);
        result.push_back(token);
        input.erase(0, pos + delimeter.length());
    }
    result.push_back(input);

    return result;
}

int main(int argc, const char * argv[])
{
    // insert code here...
    auto v = Split("abc abcd", " ");
    for (auto i : v)
    {
        cout << i <<" ";
    }

    cout << endl;
    //return 0;
}
