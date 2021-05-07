#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    string a;
    cin >> a;       //��ȣ�Է�
    int n = a.size();
    stack<int> s;
    int ans = 0;    //�踷��� ����

    for (int i = 0; i < n; i++)
    {
        if (a[i] == '(')
        {
            s.push(i);
        }
        else
        {
            if (s.top() + 1 == i)   //������ top�� �ε��� ���̰� 1�̳��� ������
            {
                s.pop();
                ans += s.size();
            }
            else                    //������ top�� �ε��� ���̰� 1�� �ƴϸ� �� ����� ���̹Ƿ� ����� ���� +1
            {
                s.pop();
                ans += 1;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}