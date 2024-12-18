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

    // DP �迭 �ʱ�ȭ, ũ��� n+1�� ����
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;  // ���� ������ 1���� ��� (0�� ĭ���� ���)

    // DP ��ȭ�� ���
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i - dice[j] >= 0) {
                dp[i] += dp[i - dice[j]];
            }
        }
    }

    // ������ ĭ���� ������ �� �ִ� ����� ���� ���
    cout << dp[n] << endl;

    return 0;
}