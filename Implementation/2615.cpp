#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci;
const int SIZE = 19;

pair<int, ci> playGame(vector<vector<int>> &board) {
    int dr[4] = {0, 1, 1, -1};
    int dc[4] = {1, 1, 0, 1};

    pair<int, ci> result;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (!board[i][j]) //0이라면
                continue;
            int go_stone = board[i][j];
            for (int k = 0; k < 4; k++) {
                int r = i;
                int c = j;
                int prev_r = i - dr[k];
                int prev_c = j - dc[k];
                if (prev_r >= 0 && prev_c >= 0 && prev_r < SIZE && board[prev_r][prev_c] == go_stone)
                    continue;
                int cnt = 1;
                while (true) {
                    r += dr[k];
                    c += dc[k];
                    if (r < 0 || c < 0 || r >= SIZE || c >= SIZE || board[r][c] != go_stone)
                        break;
                    cnt++;
                }
                if (cnt == 5) {
                    return make_pair(go_stone, ci(i + 1, j + 1));
                }
            }
        }
    }
    return make_pair(0, ci(0, 0));
}

int main() {
    vector<vector<int>> board(SIZE, vector<int>(SIZE, 0));
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            cin >> board[i][j];

    pair<int, ci> result = playGame(board);
    cout << result.first << '\n';
    if (result.first)
        cout << result.second.first << ' ' << result.second.second << '\n';

    return 0;
}