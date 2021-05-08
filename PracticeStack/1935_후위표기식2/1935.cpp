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
		if (ch >= 'A' && ch <= 'Z')					//알파벳 A to Z
		{
			s.push((double)operand[ch - 'A']);		//피연산자는 스택에 넣는다.
		}
		else										
		{											
			double op2 = s.top(); s.pop();			//연산자를 만나면 피연산자 2개를 스택에서 꺼내
			double op1 = s.top(); s.pop();
			if (ch == '+')							//계산하고
			{
				s.push(op1 + op2);					//계산된 결과를 다시 스택에 넣는다.	
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
	cout << fixed;				//소수점 아래 숫자 출력 범위 고정
	cout.precision(2);			//소수점 둘째 자리까지
	cout << s.top();
	//cout.unsetf(ios::fixed);	//해제
	return 0;
}