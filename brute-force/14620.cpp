//
// Created by BaeSuA on 2022-09-10.
//

#include <iostream>
#include <vector>

using namespace std;
const int MAX = 3000;

int n;
vector<vector<int>> board;
vector<vector<bool>> check;
int ans = MAX;

int chkFlower(int r, int c) {
    int dr[5] = {0, -1, 1, 0, 0};
    int dc[5] = {0, 0, 0, -1, 1};
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (check[nr][nc]) { // 이미 꽃 있다면
            return -1;
        }
        sum += board[nr][nc];
    }
    return sum;
}

void minFlower(int cnt, int sum) {
    if (cnt == 3) {
        ans = min(ans, sum);
        return;
    }
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            int sumFlower = chkFlower(i, j);
            if (sumFlower == -1) {
                continue;
            }
            check[i][j] = check[i - 1][j] = check[i][j - 1] = check[i + 1][j] = check[i][j + 1] = true;
            minFlower(cnt + 1, sum + sumFlower);
            check[i][j] = check[i - 1][j] = check[i][j - 1] = check[i + 1][j] = check[i][j + 1] = false;
        }
    }
}

int main() {
    // 입력
    cin >> n;
    board.assign(n, vector<int>(n, 0));
    check.assign(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    // 연산 & 출력
    minFlower(0, 0);

    cout << ans;
    return 0;
}