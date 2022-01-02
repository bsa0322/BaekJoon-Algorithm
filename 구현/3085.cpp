#include <iostream>
#include <vector>

using namespace std;

int eatCandy(int n, vector<vector<char>> board) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int r = i, c = j;
            int cnt_r = 1, cnt_c = 1;
            while (++r < n) {
                if (board[r][c] != board[i][j])
                    break;
                cnt_r++;
            }
            r = i;
            while (++c < n) {
                if (board[r][c] != board[i][j])
                    break;
                cnt_c++;
            }
            ans = max(max(cnt_r, cnt_c), ans);
            if (ans == n)
                return ans;
        }
    }
    return ans;
}

void printBoard(int n, vector<vector<char>> board) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "=========================\n";
}

int simulation(int n, vector<vector<char>> &board) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            vector<vector<char>> temp = board;
            if (i + 1 < n) {
                char t = temp[i][j];
                temp[i][j] = temp[i + 1][j];
                temp[i + 1][j] = t;
//                printBoard(n, temp);
                ans = max(ans, eatCandy(n, temp));
            }
            temp = board;
            if (j + 1 < n) {
                char t = temp[i][j];
                temp[i][j] = temp[i][j + 1];
                temp[i][j + 1] = t;
//                printBoard(n, temp);
                ans = max(ans, eatCandy(n, temp));
            }
            if (ans == n)
                return ans;
        }
    }
    return ans;
}

int main() {
    int n;

    //입력
    cin >> n;
    vector<vector<char>> board(n, vector<char>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    //연산 & 출력
    cout << simulation(n, board);
    return 0;
}