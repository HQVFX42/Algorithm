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
		// 사이클에 포함된 학생 혹은 포함되지 않은 학생을 재방문 했을 경우
		if (state[cur] == CYCLE || state[cur] == NOT_CYCLE)
		{
			cur = x;
			while (state[cur] == VISITED)	// x는 사이클에 미포함
			{
				state[cur] = NOT_CYCLE;
				cur = board[cur];
			}
			break;
		}
		// x가 아닌 다른 방문한 학생y를 재방문 했을 경우
		if (state[cur] == VISITED && cur != x)
		{
			while (state[cur] != CYCLE)	// y는 사이클에 포함
			{
				state[cur] = CYCLE;
				cur = board[cur];
			}
			cur = x;
			while (state[cur] != CYCLE)	// x는 사이클에 미포함
			{
				state[cur] = NOT_CYCLE;
				cur = board[cur];
			}
			break;
		}
		// x를 재방문했을 경우
		if (state[cur] == VISITED && cur == x)
		{
			while (state[cur] != CYCLE)	// x는 사이클에 포함
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
		state[cur] = x;	// 방문값에 x값을 넣어준다
		cur = board[cur];
		// 이번 방문에서 지나간 학생에 도달했을 경우(2,3번 케이스)
		if (state[cur] == x)
		{
			while (state[cur] != CYCLE)
			{
				state[cur] = CYCLE;
				cur = board[cur];
			}
			break;
		}
		// 이전 방문에서 지나간 학생에 도달했을 경우(1번 케이스)
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