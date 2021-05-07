#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    string a;
    cin >> a;       //괄호입력
    int n = a.size();
    stack<int> s;
    int ans = 0;    //쇠막대기 개수

    for (int i = 0; i < n; i++)
    {
        if (a[i] == '(')
        {
            s.push(i);
        }
        else
        {
            if (s.top() + 1 == i)   //스택의 top과 인덱스 차이가 1이나면 레이저
            {
                s.pop();
                ans += s.size();
            }
            else                    //스택의 top과 인덱스 차이가 1이 아니면 쇠 막대기 끝이므로 막대기 개수 +1
            {
                s.pop();
                ans += 1;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}