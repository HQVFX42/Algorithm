#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

void fastIO()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
}

class BuffManager
{
public:
	const int NONE = 0;
	const int DEFAULT_TIME = 60;

	void ApplyBuff(int buffId)
	{
		if (mBuffId == NONE)
		{
			mBuffId = buffId;
			mBuffTime = DEFAULT_TIME;
		}
		else
		{
			if (mBuffId == buffId)
			{
				mBuffTime = DEFAULT_TIME;
			}
			else
			{
				mBuffQueue.push(buffId);
			}
		}
	}

	void ExpireBuff()
	{

	}

private:
	int mBuffId = NONE;
	int mBuffTime = NONE;
	queue<int> mBuffQueue;

	int GetBuffQueueFront()
	{
		if (mBuffQueue.empty())
		{
			return NONE;
		}

		return mBuffQueue.front();
	}
};

class Guild
{
public:
	int GetGuildLevel(int guildDbId);
	bool SetGuildLevel(int guildDbId, int guildLevel);
	void AddGuild(int guildDbId, int guildLevel);
	void DeleteGuild(int guildDbId);

	std::map<int /*guildDbId*/, int /*guildLevel*/> guildLevelMap;
};

int Guild::GetGuildLevel(int guildDbId)
{
	return guildLevelMap[guildDbId];
}

bool Guild::SetGuildLevel(int guildDbId, int guildLevel)
{
	auto found = guildLevelMap.find(guildDbId);
	if (found == guildLevelMap.end())
	{
		return false;
	}

	found->second = guildLevel;
	return true;
}

void Guild::AddGuild(int guildDbId, int guildLevel)
{
	guildLevelMap[guildDbId] = guildLevel;
}

void Guild::DeleteGuild(int guildDbId)
{
	guildLevelMap.erase(guildDbId);
}

//int solution(int N)
//{
//	string strN = to_string(N);
//
//	bool isNegative = (strN[0] == '-');
//	if (isNegative) {
//		strN = strN.substr(1);
//	}
//
//	vector<int> results;
//	for (size_t pos = 0; pos < strN.length(); ++pos)
//	{
//		if (strN[pos] == '5')
//		{
//			string tempStrN = strN;
//			tempStrN.erase(pos, 1);
//
//			int tempResult = stoi(tempStrN);
//			results.push_back(isNegative ? -tempResult : tempResult);
//		}
//	}
//
//	return *max_element(results.begin(), results.end());
//}

int solution(std::vector<int>& A) {
	int N = A.size();
	int maxSum = 0;

	// Case 1: 두 개의 타일만 사용하는 경우
	for (int i = 0; i < N - 1; ++i) {
		for (int j = i + 2; j < N; ++j) {
			maxSum = std::max(maxSum, A[i] + A[i + 1] + A[j - 1] + A[j]);
		}
	}

	// Case 2: 세 개의 타일을 사용하는 경우
	for (int k = 1; k < N - 1; ++k) {
		int sumLeft = std::max(0, A[k - 1] + A[k]);
		int sumRight = std::max(0, A[k] + A[k + 1]);

		maxSum = std::max(maxSum, sumLeft + sumRight + A[k]);
	}

	return maxSum;
}

int main() {
	// 예시 테스트
	std::vector<int> A1 = { 2, 3, 5, 2, 3, 4, 6, 4, 1 };
	std::vector<int> A2 = { 1, 5, 3, 2, 6, 6, 10, 4, 7, 2, 1 };
	std::vector<int> A3 = { 1, 2, 3, 3, 2 };
	std::vector<int> A4 = { 5, 10, 3 };

	std::cout << solution(A1) << std::endl;  // 출력: 25
	std::cout << solution(A2) << std::endl;  // 출력: 35
	std::cout << solution(A3) << std::endl;  // 출력: 10
	std::cout << solution(A4) << std::endl;  // 출력: 15

	return 0;
}