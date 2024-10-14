#include <iostream>
#include <vector>

using namespace std;

int calcTen(int &r, int &c, vector<vector<int>> &board) {
    int answer = 0;
    for (int i = r - 1; i >= r - 10; i--) {
        if (i < 0) {
            break;
        }
        for (int j = c - 1; j >= c - 10; j--) {
            if (j < 0) {
                break;
            }
            int num = board[r][c] - board[r][j] - board[i][c] + board[i][j];
            if (num == 10) {
                answer++;
            }
            if (num > 10) {
                break;
            }
        }
    }
    return answer;
}

int main() {
    int m, n;

    cin >> m >> n;
    vector<vector<int>> board(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
            board[i][j] += (board[i - 1][j] + board[i][j - 1] - board[i - 1][j - 1]);
        }
    }

    int answer = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            answer += calcTen(i, j, board);
        }
    }

    cout << answer;
    return 0;
}