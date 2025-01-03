#include <iostream>
#include <vector>

using namespace std;

void fillBoard(int r, int c, int &k, vector<vector<char>> &board, char chr) {
    for (int i = r; i < r + k; i++) {
        for (int j = c; j < c + k; j++) {
            board[i][j] = chr;
        }
    }
}

vector<vector<char>> enlargeBoard(int &k) {
    vector<vector<char>> board(k * 3, vector<char>(k * 4, '.'));
    // G
    fillBoard(0, 0, k, board, 'G');
    // I
    fillBoard(k, k, k, board, 'I');
    // S
    fillBoard(k, k * 3, k, board, 'T');
    // T
    fillBoard(k * 2, k * 2, k, board, 'S');
    return board;
}

int main() {
    int k;
    cin >> k;
    vector<vector<char>> board = enlargeBoard(k);
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }
    return 0;
}