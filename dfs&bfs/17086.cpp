#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pi;

int dr[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dc[8] = {0, 0, -1, 1, -1, 1, -1, 1};

int bfs(int &n, int &m, int r, int c, vector<vector<int>> &board) {
    queue<pi> q;
    queue<int> qc;
    vector<vector<bool>> check(n, vector<bool>(m, false));

    q.push({r, c});
    qc.push(0);
    check[r][c] = true;
    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        int cnt = qc.front();
        q.pop();
        qc.pop();

        if (board[cr][cc]) {
            return cnt;
        }

        for (int i = 0; i < 8; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !check[nr][nc]) {
                check[nr][nc] = true;
                q.push({nr, nc});
                qc.push(cnt + 1);
            }
        }
    }
    return 0;
}

int main() {
    int n, m;

    cin >> n >> m;
    vector<vector<int>> board(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!board[i][j]) {
                int cnt = bfs(n, m, i, j, board);
                ans = max(ans, cnt);
            }
        }
    }

    cout << ans;
    return 0;
}