#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int F_SIZE = 3;

int getMiddleValue(int st_r, int st_c, vector<vector<int>> &board) {
    vector<int> temp;
    for (int i = st_r; i < st_r + F_SIZE; i++) {
        for (int j = st_c; j < st_c + F_SIZE; j++) {
            temp.push_back(board[i][j]);
        }
    }
    sort(temp.begin(), temp.end());

    int middle_idx = F_SIZE * F_SIZE / 2;
    return temp[middle_idx];
}


int main() {
    int r, c, t;

    cin >> r >> c;
    vector<vector<int>> board(r, vector<int>(c, 0));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> board[i][j];
        }
    }
    cin >> t;

    int ans = 0; // 중앙값이 t 보다 큰 원소 개수 구하기
    for (int i = 0; i <= r - F_SIZE; i++) {
        for (int j = 0; j <= c - F_SIZE; j++) {
            int cnt = getMiddleValue(i, j, board);
            ans += (cnt >= t);
        }
    }

    cout << ans;
    return 0;
}