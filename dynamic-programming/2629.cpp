#include <iostream>
#include <vector>

using namespace std;
const int MAX = 40000;

vector<int> checkAvailable(int n, vector<int> &weights) {
    vector<vector<int>> dp(n + 1, vector<int>(MAX + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < weights[i - 1]; j++) {
            dp[i][j] = dp[i - 1][j];
        }
        for (int j = MAX; j >= weights[i - 1]; j--) {
            if (dp[i - 1][j - weights[i - 1]] == 1) {
                dp[i][j] = 1;

                int temp = abs(weights[i - 1] - (j - weights[i - 1]));
                if (temp > 0 && temp <= MAX) {
                    dp[i][temp] = 1;
                }
            }
        }
    }
    return dp[n];
}

/**
 * 양팔저울에서 양 옆에 둬서 빼는 경우까지 고려해야 하므로 1차원 냅색으로는 해결 불가 !!
 */

int main() {
    int n, m, w;
    cin >> n;
    vector<int> weights(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    // 최대 무게까지 만들 수 있는지 미리 확인
    vector<int> dp = checkAvailable(n, weights);

    cin >> m;
    while (m--) {
        cin >> w;
        if (dp[w] == 0) {
            cout << "N ";
        } else {
            cout << "Y ";
        }
    }
    return 0;
}