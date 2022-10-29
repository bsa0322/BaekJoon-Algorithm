//
// Created by BaeSuA on 2022-10-30.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;

int bfs(int height, int n, vector<vector<int>> &board) {
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    int area = 0; //안전 구역 개수
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && board[i][j] > height) {
                area++;
                visited[i][j] = true;
                queue<ci> q;
                q.push({i, j});
                while (!q.empty()) {
                    int r = q.front().first;
                    int c = q.front().second;
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        int nr = r + dr[k];
                        int nc = c + dc[k];
                        if (nr < 0 || nr >= n || nc < 0 || nc >= n || visited[nr][nc] || board[nr][nc] <= height) {
                            continue;
                        }
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
        }
    }
    return area;
}

/**
 * 비가 하나도 안 올수도 있다..!
 */

int main() {
    int n, mx = 0, ans = 0;

    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            mx = max(mx, board[i][j]);
        }
    }

    for (int i = mx - 1; i >= 0; i--) {
        ans = max(ans, bfs(i, n, board));
    }
    cout << ans;
    return 0;
}