#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string s;
    cin >> s;

    for (int i = 'a'; i <= 'z'; i++)
    {
        cout << count(s.begin(), s.end(), i) << ' ';        //count함수를 이용하여 문자열의 begin부터 end까지 개수
    }

    cout << '\n';

    return 0;
}