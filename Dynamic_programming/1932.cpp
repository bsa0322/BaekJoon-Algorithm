#include <iostream>
#include <cstring>

using namespace std;

int triangle[501][501];
int dp[501][501];

int f(int row, int col) {
    if (row == 1)
        return triangle[1][1];
    if (row == 0 || col == 0) //정수 삼각형 값이 없는 곳
        return 0;
    if (dp[row][col] >= 0) //값이 이미 존재한다면
        return dp[row][col];
    return dp[row][col] = max(f(row - 1, col - 1), f(row - 1, col)) + triangle[row][col];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, ans = 0;
    cin >> n;

    memset(dp, -1, sizeof(dp));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> triangle[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        int t = f(n, i);
        if (ans < t)
            ans = t;
    }

    cout << ans;

    return 0;
}