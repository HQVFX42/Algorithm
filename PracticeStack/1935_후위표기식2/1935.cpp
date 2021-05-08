#include <iostream>
#include <stack>
using namespace std;
int operand[26];

int main()
{
	int n;
	cin >> n;
	string postfix;
	cin >> postfix;
	for (int i = 0; i < n; i++)
	{
		cin >> operand[i];
	}
	stack<double> s;
	for (char ch : postfix)
	{
		if (ch >= 'A' && ch <= 'Z')					//���ĺ� A to Z
		{
			s.push((double)operand[ch - 'A']);		//�ǿ����ڴ� ���ÿ� �ִ´�.
		}
		else										
		{											
			double op2 = s.top(); s.pop();			//�����ڸ� ������ �ǿ����� 2���� ���ÿ��� ����
			double op1 = s.top(); s.pop();
			if (ch == '+')							//����ϰ�
			{
				s.push(op1 + op2);					//���� ����� �ٽ� ���ÿ� �ִ´�.	
			}
			else if (ch == '-')
			{
				s.push(op1 - op2);
			}
			else if (ch == '*')
			{
				s.push(op1 * op2);
			}
			else if (ch == '/')
			{
				s.push(op1 / op2);
			}
		}
	}
	cout << fixed;				//�Ҽ��� �Ʒ� ���� ��� ���� ����
	cout.precision(2);			//�Ҽ��� ��° �ڸ�����
	cout << s.top();
	//cout.unsetf(ios::fixed);	//����
	return 0;
}