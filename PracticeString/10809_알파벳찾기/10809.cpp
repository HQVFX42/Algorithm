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
        auto it = find(s.begin(), s.end(), i);          //find�Լ��� �̿��Ͽ� i�� ã���� �ش� ������ �ݺ��ڸ� ��ȯ���ָ� �������� ������ �ش� ������ ������ end() �ݺ��ڸ� ��ȯ
        if (it == s.end())                              //�� ã�� ���
        {
            cout << -1 << ' ';
        }
        else                                            //ã�� ���
        {
            cout << (it - s.begin()) << ' ';            //�� ���ĺ��� �� ��°�� ó�� �����ϴ��� 0��°~
        }
    }
    cout << '\n';
    
    return 0;
}