//P3
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <tuple>

using namespace std;

// 정확한 위치와 글자 수를 검사하는 함수
pair<int, int> Check(const string& List, const string& Guess)
{
	int A = 0, B = 0;
	vector<bool> UsedInList(4, false), UsedInGuess(4, false);

	// 위치가 같은 글자 수 계산
	for (int i = 0; i < 4; ++i)
	{
		if (List[i] == Guess[i])
		{
			++A;
			UsedInList[i] = UsedInGuess[i] = true;
		}
	}

	// 위치가 다른 글자 수 계산
	for (int i = 0; i < 4; ++i)
	{
		if (!UsedInGuess[i])
		{
			for (int j = 0; j < 4; ++j)
			{
				if (!UsedInList[j] && List[j] == Guess[i])
				{
					++B;
					UsedInList[j] = true;
					break;
				}
			}
		}
	}

	return { A, B };
}

int main()
{
	int N;
	cin >> N;
	vector<tuple<string, int, int>> Questions(N);

	for (int i = 0; i < N; ++i) {
		string S;
		int A;
		int B;
		cin >> S >> A >> B;
		Questions[i] = make_tuple(S, A, B);
	}

	set<string> Answers;
	const string Char1 = "bdgnprst";
	const string Char2 = "aeiou";

	for (char C1 : Char1) {
		for (char C2 : Char2) {
			for (char C3 : Char1) {
				if (C1 == C3)
				{
					continue; // 조건: 첫과 세 번째 글자는 달라야 함
				}
				for (char C4 : Char2)
				{
					if (C2 == C4)
					{
						continue; // 조건: 두 번째와 네 번째 글자는 달라야 함
					}
					string Candidate = { C1, C2, C3, C4 };
					bool bPossible = true;
					for (const auto& Question : Questions)
					{
						const string& q = get<0>(Question);
						int a = get<1>(Question);
						int b = get<2>(Question);
						if (Check(Candidate, q) != make_pair(a, b))
						{
							bPossible = false;
							break;
						}
					}
					if (bPossible)
					{
						Answers.insert(Candidate);
					}
				}
			}
		}
	}

	if (Answers.size() == 1)
	{
		cout << *Answers.begin() << endl;
	}
	else
	{
		cout << "x" << endl;
	}

	return 0;
}