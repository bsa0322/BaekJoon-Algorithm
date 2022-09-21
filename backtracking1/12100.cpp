#include <iostream>
#include <vector>

using namespace std;

int ans;

void game2048(int n, int cnt, vector<vector<int>> _board) {
    if (cnt >= 5) return;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << _board[i][j] << ' ';
        }
        cout << '\n';
    }

    //상
    vector<vector<int>> board = _board;
    for (int i = 0; i < n; i++) {
        int cnt = -1;
        for (int j = 0; j < n - 1; j++) {
            if (board[j][i] == board[j + 1][i]) {
                if (ans < board[j][i] + board[j + 1][i])
                    ans = board[j][i] + board[j + 1][i];
                if (cnt == -1) cnt = j;
                board[cnt++][i] = board[j][i] + board[j + 1][i];
                j++;
            }
        }
    }
    game2048(n, cnt + 1, board);

    //하
    board = _board;
    for (int i = 0; i < n; i++) {
        int cnt = -1;
        for (int j = n - 1; j > 0; j--) {
            if (board[j][i] == board[j - 1][i]) {
                if (ans < board[j][i] + board[j - 1][i])
                    ans = board[j][i] + board[j - 1][i];
                if (cnt == -1) cnt = j;
                board[cnt--][i] = board[j][i] + board[j - 1][i];
                j++;
            }
        }
    }
    game2048(n, cnt + 1, board);

    //좌
    board = _board;
    for (int i = 0; i < n; i++) {
        int cnt = -1;
        for (int j = 0; j < n - 1; j++) {
            if (board[i][j] == board[i][j + 1]) {
                if (ans < board[i][j] + board[i][j + 1])
                    ans = board[i][j] + board[i][j + 1];
                if (cnt == -1) cnt = j;
                board[i][cnt++] = board[i][j] + board[i][j + 1];
                j++;
            }
        }
    }
    game2048(n, cnt + 1, board);

    //우
    board = _board;
    for (int i = 0; i < n; i++) {
        int cnt = -1;
        for (int j = n - 1; j > 0; j--) {
            if (board[i][j] == board[i][j - 1]) {
                if (ans < board[i][j] + board[i][j - 1])
                    ans = board[i][j] + board[i][j - 1];
                if (cnt == -1) cnt = j;
                board[i][cnt--] = board[i][j] + board[i][j - 1];
                j++;
            }
        }
    }
    game2048(n, cnt + 1, board);

}

int main() {
    int n;

    //입력
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (ans < board[i][j]) ans = board[i][j];
        }
    }

    //연산
    game2048(n, 0, board);

    //출력
    cout << ans << '\n';

    return 0;
}