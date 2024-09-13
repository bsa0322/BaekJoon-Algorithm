#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    vector<int> dp(46, 0);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= 45; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cin >> n;
    cout << dp[n];
    return 0;
}