//
//  2979.cpp
//  Algothingy
//
//  Created by carroll on 12/6/23.
//

/* 2979 트럭 주차 https://www.acmicpc.net/problem/2979 */
#include <bits/stdc++.h>

using namespace std;

void fastIO()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
}

int a,b,c;
int cnt[111];
int main()
{
    cout << sizeof(int) << "\n";
    cout << sizeof(cnt) << "\n";
    cout << sizeof(*cnt) << "\n";
    cout << sizeof(cnt) / sizeof(*cnt)  << "\n";
    cin >> a >> b >> c;
    for (int i = 0; i < 3; i++) {
        int start, end;
        cin >> start >> end;
        for (int j = start; j < end; j++) {
            cnt[j]++;
        }
    }
    
    int result = 0;
    for (int i = 1; i < sizeof(cnt) / sizeof(*cnt); i++) {
        if (cnt[i] == 1) {
            result += a * 1;
        }
        else if (cnt[i] == 2) {
            result += b * 2;
        }
        else if (cnt[i] == 3) {
            result += c * 3;
        }
    }
    
    cout << result;
}
