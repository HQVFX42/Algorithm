#include <bits/stdc++.h>
using namespace std;

int board[100000];
int state[100000];
int n;

const int NOT_VISITED = 0;
const int VISITED = 1;
const int CYCLE = -1;
const int NOT_CYCLE = 3;

void run1(int x)
{
	auto cur = x;
	while (true)
	{
		state[cur] = VISITED;
		cur = board[cur];
		// ����Ŭ�� ���Ե� �л� Ȥ�� ���Ե��� ���� �л��� ��湮 ���� ���
		if (state[cur] == CYCLE || state[cur] == NOT_CYCLE)
		{
			cur = x;
			while (state[cur] == VISITED)	// x�� ����Ŭ�� ������
			{
				state[cur] = NOT_CYCLE;
				cur = board[cur];
			}
			break;
		}
		// x�� �ƴ� �ٸ� �湮�� �л�y�� ��湮 ���� ���
		if (state[cur] == VISITED && cur != x)
		{
			while (state[cur] != CYCLE)	// y�� ����Ŭ�� ����
			{
				state[cur] = CYCLE;
				cur = board[cur];
			}
			cur = x;
			while (state[cur] != CYCLE)	// x�� ����Ŭ�� ������
			{
				state[cur] = NOT_CYCLE;
				cur = board[cur];
			}
			break;
		}
		// x�� ��湮���� ���
		if (state[cur] == VISITED && cur == x)
		{
			while (state[cur] != CYCLE)	// x�� ����Ŭ�� ����
			{
				state[cur] = CYCLE;
				cur = board[cur];
			}
			break;
		}
	}
}

void run2(int x)
{
	auto cur = x;
	while (true)
	{
		state[cur] = x;	// �湮���� x���� �־��ش�
		cur = board[cur];
		// �̹� �湮���� ������ �л��� �������� ���(2,3�� ���̽�)
		if (state[cur] == x)
		{
			while (state[cur] != CYCLE)
			{
				state[cur] = CYCLE;
				cur = board[cur];
			}
			break;
		}
		// ���� �湮���� ������ �л��� �������� ���(1�� ���̽�)
		else if (state[cur] != 0)
		{
			break;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int TC;
	cin >> TC;
	while (TC--)
	{
		cin >> n;
		fill(state + 1, state + n + 1, 0);
		for (int i = 1; i <= n; i++)
		{
			cin >> board[i];
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			if (state[i] == NOT_VISITED)
			{
				//run1(i);
				run2(i);
			}
		}
		int cnt = 0;
		// run1
		/*for (int i = 1; i <= n; i++)
		{
			if (state[i] == NOT_CYCLE) cnt++;
		}*/
		// run2
		for (int i = 1; i <= n; i++)
		{
			if (state[i] != CYCLE) cnt++;
		}
		cout << cnt << '\n';
	}
}