#include <iostream>
#include <vector>

using namespace std;

int getCntExplode(int &cr, int &cc, int &r, int &c, vector<string> &board) {
    int dr[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int dc[8] = {0, 0, -1, 1, -1, 1, -1, 1};
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        int nr = cr + dr[i];
        int nc = cc + dc[i];
        if (nr >= 0 && nr < r && nc >= 0 && nc < c && board[nr][nc] == '*') {
            cnt++;
        }
    }
    return cnt;
}

vector<string> countExplode(int &r, int &c, vector<string> &board) {
    vector<string> cnt_board = board;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (board[i][j] == '*') {
                continue;
            }
            cnt_board[i][j] = getCntExplode(i, j, r, c, board) + '0';
        }
    }
    return cnt_board;
}

int main() {
    int r, c;

    while (cin >> r >> c) {
        if (r == 0 && c == 0) {
            break;
        }
        vector<string> board(r);
        for (int i = 0; i < r; i++) {
            cin >> board[i];
        }
        // 지뢰 개수 세기
        vector<string> cnt_board = countExplode(r, c, board);
        for (int i = 0; i < r; i++) {
            cout << cnt_board[i] << '\n';
        }
    }
    return 0;
}