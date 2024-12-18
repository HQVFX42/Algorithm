//
//  2309.cpp
//  Algothingy
//
//  Created by carroll on 12/6/23.
//

/* 2309 일곱난쟁이 https://www.acmicpc.net/problem/2309 */
#include <bits/stdc++.h>

using namespace std;

const int SIZE = 9;
int a[SIZE];

int main()
{
    for (int i = 0; i < SIZE; i++) {
        cin >> a[i];
    }
    sort(a, a + SIZE);
    
    do {
        int sum = 0;
        for (int i = 0; i < 7; i++) {
            sum += a[i];
        }
        
        if (sum == 100) {
            break;
        }
    } while (next_permutation(a, a + SIZE));
    
    for (int i = 0; i < 7; i++) {
        cout << a[i] << '\n';
    }
}
