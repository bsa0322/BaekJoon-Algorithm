#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;

queue<ci> bfs(int n, int m, vector<vector<int>> &board) {
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    vector<vector<bool>> check(n, vector<bool>(m, false));
    queue<ci> q;
    queue<ci> cheese; //녹을 치즈

    q.push({0, 0});
    check[0][0] = true;
    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if (nr < 0 || nr >= n || nc < 0 || nc >= m || check[nr][nc] || board[nr][nc])
                continue;

            q.push({nr, nc});
            check[nr][nc] = true;
            for (int j = 0; j < 4; j++) { //주변에 치즈 있는지 찾기
                int tr = nr + dr[j];
                int tc = nc + dc[j];
                if (tr < 0 || tr >= n || tc < 0 || tc >= m)
                    continue;

                if (board[tr][tc])
                    board[tr][tc]++;
                if (board[tr][tc] == 3)
                    cheese.push({tr, tc});
            }
        }
    }
    return cheese;
}

int main() {
    int n, m;

    //입력
    cin >> n >> m;
    vector<vector<int>> board(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    //연산
    int ans = 0;
    while (true) {
        queue<ci> cheese = bfs(n, m, board);
        if (cheese.empty()) //더 이상 녹일 치즈가 없다면
            break;

//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < m; j++) {
//                cout << board[i][j] << ' ';
//            }
//            cout << '\n';
//        }
//        cout << "=========================\n";

        while (!cheese.empty()) {
            int r = cheese.front().first;
            int c = cheese.front().second;
            cheese.pop();

            board[r][c] = 0;
        }
        for (int i = 0; i < n; i++) { //공기와 닿아서 변했던 보드 다시 초기화
            for (int j = 0; j < m; j++) {
                if (board[i][j])
                    board[i][j] = 1;
            }
        }
        ans++;
    }

    //출력
    cout << ans << '\n';
    return 0;
}