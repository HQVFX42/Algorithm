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
        auto it = find(s.begin(), s.end(), i);          //find함수를 이용하여 i를 찾으면 해당 원소의 반복자를 반환해주며 존재하지 않으면 해당 범위의 마지막 end() 반복자를 반환
        if (it == s.end())                              //못 찾은 경우
        {
            cout << -1 << ' ';
        }
        else                                            //찾은 경우
        {
            cout << (it - s.begin()) << ' ';            //각 알파벳이 몇 번째에 처음 등장하는지 0번째~
        }
    }
    cout << '\n';
    
    return 0;
}