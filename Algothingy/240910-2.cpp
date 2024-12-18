// P2
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<int> dice(m);
    for (int i = 0; i < m; ++i) {
        cin >> dice[i];
    }

    // DP 배열 초기화, 크기는 n+1로 설정
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;  // 시작 지점은 1가지 방법 (0번 칸에서 출발)

    // DP 점화식 계산
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i - dice[j] >= 0) {
                dp[i] += dp[i - dice[j]];
            }
        }
    }

    // 마지막 칸에서 도달할 수 있는 방법의 수를 출력
    cout << dp[n] << endl;

    return 0;
}