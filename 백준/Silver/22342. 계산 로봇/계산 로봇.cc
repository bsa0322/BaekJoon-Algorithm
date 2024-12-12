#include <iostream>
#include <vector>

using namespace std;

typedef struct Robot {
    int save, out;
} robot;

int getMaximumValue(int &m, int &n, vector<vector<int>> &weights) {
    vector<vector<robot>> board(m, vector<robot>(n, {0}));
    int d[3] = {-1, 0, 1}; // 행 기준 방향 배열

    // 첫 번째 열 초기화
    for (int i = 0; i < m; i++) {
        board[i][0].out = weights[i][0];
    }

    // m * (n-1) 돌면서 저장 값 중 최댓 값 구하기
    int ans = 0;
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < m; i++) {
            for (int k = 0; k < 3; k++) {
                int r = i + d[k];
                if (r < 0 || r >= m) {
                    continue;
                }
                board[i][j].save = max(board[i][j].save, board[r][j - 1].save);
                board[i][j].save = max(board[i][j].save, board[r][j - 1].out);
            }
            board[i][j].out = board[i][j].save + weights[i][j];
            ans = max(ans, board[i][j].save);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    char temp;
    int m, n;
    cin >> m >> n;
    vector<vector<int>> weights(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> temp;
            weights[i][j] = temp - '0';
        }
    }

    cout << getMaximumValue(m, n, weights);
    return 0;
}