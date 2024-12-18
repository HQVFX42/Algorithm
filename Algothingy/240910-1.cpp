// P1
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int N;
	int Q;
	string M;
	cin >> N >> M >> Q;

	vector<int> PrefixSum(N + 1, 0);
	vector<int> Aster;

	for (int i = 0; i < N; ++i)
	{
		if (M[i] == '*')
		{
			Aster.push_back(i);
		}

		PrefixSum[i + 1] = PrefixSum[i];
		if (M[i] >= '1' && M[i] <= '3')
		{
			PrefixSum[i + 1] += M[i] - '0';
		}
	}

	for (int i = 0; i < Q; ++i)
	{
		int S;
		int E;
		cin >> S >> E;

		auto FirstAster = lower_bound(Aster.begin(), Aster.end(), S);
		auto LastAster = upper_bound(Aster.begin(), Aster.end(), E);

		if (FirstAster == Aster.end() || FirstAster == LastAster || *FirstAster >= E)
		{
			cout << 0 << endl;
		}
		else
		{
			int Start = *FirstAster;
			int End = *(--LastAster);

			if (Start < End)
			{
				cout << PrefixSum[End] - PrefixSum[Start + 1] << endl;
			}
			else
			{
				cout << 0 << endl;
			}
		}
	}

	return 0;
}