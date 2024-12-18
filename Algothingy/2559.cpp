//
//  2559.cpp
//  Algothingy
//
//  Created by carroll on 12/12/23.
//

#include <bits/stdc++.h>

using ll = long long;

using namespace std;

void fastIO()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
}

int main()
{
    int n;
    int k;
    cin >> n >> k;
    
    int ans = -11111111;
    int psum[111111] = {};
    
    for (int i = 1; i <= n; i++)
    {
        int tmp;
        cin >> tmp;
        psum[i] = psum[i - 1] + tmp;
    }
    
    for (int i = k; i <= n; i++) 
    {
        ans = max(ans, psum[i] - psum[i - k]);
    }
    
    cout << ans;
}
