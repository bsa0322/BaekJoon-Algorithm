//
// Created by BaeSuA on 2022-12-09.
//

#include <iostream>
#include <vector>

using namespace std;
const int MOD = 10007;

int main() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);

    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] %= MOD;
    }

    cout << dp[n];
    return 0;
}