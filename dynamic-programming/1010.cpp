#include <iostream>
#include <vector>

using namespace std;
const int INF = 30;

/**
 * 처음에 어째선지 모르겠지만 전깃줄 문제랑 헷갈림...... LIS 쓰는 거라 생각함
 * 그냥 단순한 DP 문제였음. 조합을 DP로 구현하면 됨
 */

int main() {
    int t, n, m;
    vector<vector<int>> dp(INF, vector<int>(INF, 1));
    for (int i = 1; i < INF; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = dp[i][j - 1] * (i - j + 1) / j;
        }
    }

    cin >> t;
    while (t--) {
        cin >> n >> m;
        cout << dp[m][n] << '\n';
    }
    return 0;
}