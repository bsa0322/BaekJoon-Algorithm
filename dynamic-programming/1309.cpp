#include <iostream>
#include <vector>

using namespace std;

#define MOD 9901

/** https://www.acmicpc.net/problem/1309
 * 사자 배치하는 경우의 수 구하기 (가로, 세로 붙어있게 X)
 * 한 행에 대해 아래 3가지 경우로 분류 가능!!
 *  - 왼쪽, 오른쪽 모두 사자 없음 (0)
 *  - 왼쪽만 사자 있음 (1)
 *  - 오른쪽만 사자 있음 (2)
 * 따라서 [N][3] 크기의 DP 배열을 만들어 해결 가능 !!
 *
 * @return 경우의 수 % 9901
 */

int main() {
    int n;

    cin >> n;
    vector<vector<int>> dp(n, vector<int>(3, 0));

    dp[0][0] = dp[0][1] = dp[0][2] = 1;
    for (int i = 1; i < n; i++) {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
    }

    cout << (dp[n - 1][0] + dp[n - 1][1] + dp[n - 1][2]) % MOD;
    return 0;
}