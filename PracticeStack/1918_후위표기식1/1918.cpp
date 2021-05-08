#include <iostream>
#include <stack>
using namespace std;

int precedence(char ch)						//������ �켱���� ���ϱ�
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
		else if (ch == '(')					//��ȣ�� �ִ� ��� ���� ��ȣ�� ���ÿ� �ְ�
		{
			ops.push(ch);
		}
		else if (ch == ')')					//��ȣ�� �ִ� ��� �ݴ� ��ȣ�� ���� ��ȣ�� ���� �� ���� ���ÿ��� ����ؼ� �����ڸ� ����
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
				&& precedence(ops.top()) >= precedence(ch)) //�������� �켱������ ������ ���� ���� �ִ� �������� �켱�������� �۰ų� ���� ���� ���ÿ� �ִ� �����ڸ� ����� �߰��Ѵ�.
			{
				ans += ops.top();
				ops.pop();
			}
			ops.push(ch);
		}
	}
	while (!ops.empty())					//��� ������/�ǿ����� ó���� ������, ������ ���ÿ� �ִ� �����ڸ� �ϳ��� ����� �߰��Ѵ�.
	{
		char op = ops.top();
		ops.pop();
		ans += op;
	}

	cout << ans << '\n';
	return 0;
}