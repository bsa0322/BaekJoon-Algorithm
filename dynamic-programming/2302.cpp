//
// Created by BaeSuA on 2023-10-17.
//

#include <iostream>
#include <vector>

using namespace std;

int getMethods(int n, vector<bool> &fixed) {
    vector<int> dp(n + 1, 0);

    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (fixed[i]) {
            dp[i] = dp[i - 1];
            continue;
        }
        dp[i] = dp[i - 1];
        if (!fixed[i - 1]) {
            dp[i] += dp[i - 2];
        }
    }
    return dp[n];
}

int main() {
    int n, m, stair;

    cin >> n >> m;
    vector<bool> fixed(n + 1, false);
    for (int i = 0; i < m; i++) {
        cin >> stair;
        fixed[stair] = true;
    }

    cout << getMethods(n, fixed);
    return 0;
}