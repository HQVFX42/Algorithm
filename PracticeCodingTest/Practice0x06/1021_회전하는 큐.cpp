#include <bits/stdc++.h>
using namespace std;

int main()
{
	deque<int> dq;
	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		dq.push_back(i);
	}
	int ans = 0;
	while (M--)
	{
		int pos;
		cin >> pos;
		int index = find(dq.begin(), dq.end(), pos) - dq.begin();
		while (dq.front() != pos)
		{
			if (index < dq.size() - index)	//왼쪽으로 이동
			{
				dq.push_back(dq.front());
				dq.pop_front();
			}
			else							//오른쪽으로 이동
			{
				dq.push_front(dq.back());
				dq.pop_back();
			}
			ans++;
		}
		dq.pop_front();
	}
	cout << ans;
}