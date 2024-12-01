#include <iostream>
#include <vector>

using namespace std;
const int INF = -(1e8 + 1);

int getMaximumCost(int &n, int &m, vector<vector<int>> &board) {
    // (x, y, z): {x, y} - board 위치, z - 0번 인덱스(왼쪽에서 오는 경우), 1번 인덱스(오른쪽에서 오는 경우)
    vector<vector<vector<int>>> dp_temp(n + 1, vector<vector<int>>(m + 2, vector<int>(2, INF)));
    vector<vector<int>> dp(n + 1, vector<int>(m + 2, INF)); // 실제 정답

    // 첫 번째 행 초기화
    dp[1][0] = 0;
    for (int j = 1; j <= m; j++) {
        dp[1][j] = dp[1][j - 1] + board[1][j];
    }

    // 2 번째 행부터 왼쪽, 오른쪽, 위쪽 중 최댓값 구하기
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp_temp[i][j][0] = max(board[i][j] + dp[i - 1][j], board[i][j] + dp_temp[i][j - 1][0]);
            int right_idx = m - j + 1;
            dp_temp[i][right_idx][1] = max(board[i][right_idx] + dp[i - 1][right_idx],
                                           board[i][right_idx] + dp_temp[i][right_idx + 1][1]);
        }
        for (int j = 1; j <= m; j++) {
            dp[i][j] = max(dp_temp[i][j][0], dp_temp[i][j][1]);
        }
    }
    return dp[n][m];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> board(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> board[i][j];
        }
    }

    cout << getMaximumCost(n, m, board);
    return 0;
}