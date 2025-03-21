#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int> pi;

vector<vector<int>> getDist(int r, int c, int &n, int &m, vector<vector<int>> &board) {
    vector<vector<int>> dist(n, vector<int>(m, 0));
    vector<vector<bool>> check(n, vector<bool>(m, false));
    queue<pi> q;

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    dist[r][c] = 0;
    check[r][c] = true;
    q.push({r, c});
    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        int ct = dist[cr][cc];
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if (nr < 0 || nr >= n || nc < 0 || nc >= m || !board[nr][nc] || check[nr][nc]) {
                continue;
            }

            check[nr][nc] = true;
            dist[nr][nc] = ct + 1;
            q.push({nr, nc});
        }
    }
    return dist;
}

int main() {
    int n, m, str, stc;
    cin >> n >> m;
    vector<vector<int>> board(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) {
                str = i;
                stc = j;
            }
        }
    }
    vector<vector<int>> ans = getDist(str, stc, n, m, board);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (ans[i][j] == 0 && board[i][j] == 1) {
                cout << -1 << ' ';
            } else {
                cout << ans[i][j] << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}