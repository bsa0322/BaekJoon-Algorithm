#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci;

const int SIZE = 256;
const int INF = 64 * 1e6 * 2 + 1;

vector<vector<int>> board;

int calcTime(int n, int m, int b, int height) {
    int t = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] > height) {
                int cnt = board[i][j] - height;
                t += (cnt * 2);
                b += cnt;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] < height) {
                int cnt = height - board[i][j];
                if (cnt > b)
                    return INF;
                t += cnt;
                b -= cnt;
            }
        }
    }
    return t;
}

ci calcAns(int n, int m, int b) {
    ci ans = {INF, INF};
    for (int i = SIZE; i >= 0; i--) {
        int t = calcTime(n, m, b, i);
        if (ans.first > t)
            ans = {t, i};
    }
    return ans;
}

int main() {
    int n, m, b; //b: 가지고 있는 땅 개수

    //입력
    cin >> n >> m >> b;
    board.assign(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    //연산 & 출력
    ci ans = calcAns(n, m, b);
    cout << ans.first << ' ' << ans.second << '\n';
    return 0;
}