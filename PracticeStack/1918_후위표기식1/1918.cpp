#include <iostream>
#include <stack>
using namespace std;

int precedence(char ch)						//연산자 우선순위 정하기
{
	if (ch == '(') return 0;
	if (ch == '+' || ch == '-') return 1;
	else return 2;
}

int main()
{
	string s;
	cin >> s;

	string ans;
	stack<char> ops;

	for (char ch : s)
	{
		if ('A' <= ch && ch <= 'Z')			//A to Z
		{
			ans += ch;
		}
		else if (ch == '(')					//괄호가 있는 경우 여는 괄호는 스택에 넣고
		{
			ops.push(ch);
		}
		else if (ch == ')')					//괄호가 있는 경우 닫는 괄호는 여는 괄호가 나올 때 까지 스택에서 계속해서 연산자를 꺼냄
		{
			while (!ops.empty())
			{
				char op = ops.top();
				ops.pop();
				if (op == '(') break;
				ans += op;
			}
		}
		else
		{
			while (!ops.empty()
				&& precedence(ops.top()) >= precedence(ch)) //연산자의 우선순위가 스택의 가장 위에 있는 연산자의 우선순위보다 작거나 같은 동안 스택에 있는 연산자를 결과에 추가한다.
			{
				ans += ops.top();
				ops.pop();
			}
			ops.push(ch);
		}
	}
	while (!ops.empty())					//모든 연산자/피연산자 처리가 끝나면, 연산자 스택에 있는 연산자를 하나씩 결과에 추가한다.
	{
		char op = ops.top();
		ops.pop();
		ans += op;
	}

	cout << ans << '\n';
	return 0;
}