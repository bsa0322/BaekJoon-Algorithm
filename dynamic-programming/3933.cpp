#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int INF = 1 << 15;
const int CNT = 4;

int main() {
    // 0: 숫자, 1: 제곱수 개수, 2: 가장 큰 첫 시작 제곱수
    vector<vector<vector<int>>> dp(INF, vector<vector<int>>(CNT + 1, vector<int>(0)));

    dp[0][0].push_back(0);
    for (int i = 1; i < INF; i++) {
        for (int j = sqrt(i); j > 0; j--) {
            int prev = i - j * j;
            for (int k = 1; k <= CNT; k++) {
                for (int l = 0; l < dp[prev][k - 1].size(); l++) {
                    if (dp[prev][k - 1][l] <= j) {
                        dp[i][k].push_back(j);
                    }
                }
            }
        }
    }

    int n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        cout << dp[n][1].size() + dp[n][2].size() + dp[n][3].size() + dp[n][4].size() << '\n';
    }
    return 0;
}