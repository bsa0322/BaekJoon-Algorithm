#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
typedef vector<vector<int>> matrix;
typedef tuple<int, int, int> tp;

int bfs(int h, int n, int m, int cnt, vector<matrix> &board) {
    //위, 아래, 왼, 오, 앞, 뒤
    int dh[6] = {-1, 1, 0, 0, 0, 0};
    int dn[6] = {0, 0, 0, 0, -1, 1};
    int dm[6] = {0, 0, -1, 1, 0, 0};

    queue<tp> q;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (board[i][j][k] == 1)
                    q.push({i, j, k});
            }
        }
    }

    int ans = 1;
    while (!q.empty()) {
        int ch = get<0>(q.front());
        int cn = get<1>(q.front());
        int cm = get<2>(q.front());
        q.pop();
        cnt--;
        ans = board[ch][cn][cm];

        if (cnt == 0)
            return ans - 1;

        for (int i = 0; i < 6; i++) {
            int nh = ch + dh[i];
            int nn = cn + dn[i];
            int nm = cm + dm[i];
            if (nh < 0 || nh >= h || nm < 0 || nm >= m || nn < 0 || nn >= n || board[nh][nn][nm] != 0)
                continue;

            board[nh][nn][nm] = ans + 1;
            q.push({nh, nn, nm});
        }
    }
    if (cnt == 0)
        return ans - 1;
    return -1;
}

int main() {
    int m, n, h, cnt = 0;

    //입력
    cin >> m >> n >> h;
    vector<matrix> board(h, matrix(n, vector<int>(m, 0)));
    cnt = h * m * n;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> board[i][j][k];
                if (board[i][j][k] == -1)
                    cnt--;
            }
        }
    }

    //연산 & 출력
    cout << bfs(h, n, m, cnt, board) << '\n';
//    for (int i = 0; i < h; i++) {
//        for (int j = 0; j < n; j++) {
//            for (int k = 0; k < m; k++) {
//                cout << board[i][j][k] << ' ';
//            }
//            cout << '\n';
//        }
//    }
    return 0;
}