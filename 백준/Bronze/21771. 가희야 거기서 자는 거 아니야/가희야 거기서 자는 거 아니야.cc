#include <iostream>
#include <vector>

using namespace std;

bool hidePillow(int r, int c, int rp, int cp, vector<vector<char>> &board) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (board[i][j] == 'P') {
                for (int k = i; k < i + rp; k++) {
                    if (k >= r) {
                        return true;
                    }
                    for (int l = j; l < j + cp; l++) {
                        if (l >= c) {
                            return true;
                        }
                        if (board[k][l] == 'G') {
                            return true;
                        }
                    }
                }
                return false;
            }
        }
    }
}

int main() {
    int r, c, rg, rp, cg, cp;
    cin >> r >> c >> rg >> cg >> rp >> cp;
    vector<vector<char>> board(r, vector<char>(c, ' '));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> board[i][j];
        }
    }

    cout << hidePillow(r, c, rp, cp, board);

    return 0;
}