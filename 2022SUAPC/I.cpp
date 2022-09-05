//
// Created by BaeSuA on 2022-09-04.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k, total_seeds = 0;

    cin >> n >> m >> k;
    vector<vector<int>> board(n, vector<int>(m, 0));
    vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(2, false)));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j]) {
                total_seeds++;
            }
        }
    }
    if (total_seeds == k * 2) {
        cout << 0;
        return 0;
    }
    int seeds = 0;
    // 열 검사
    for (int i = 0; i < n - k + 1; i++) {
        for (int j = 0; j < m; j++) {
            if (!board[i + k - 1][j]) {
                continue;
            }
            // 열으로 세기
            if (board[i][j] && !visited[i][j][1]) {
                bool chk = true;
                for (int l = i; l < i + k; l++) {
                    if (!board[l][j]) {
                        chk = false;
                        break;
                    }
                }
                if (chk) {
                    visited[i][j][1] = true;
                    seeds++;
                    for (int l = i; l < i + k; l++) {
                        board[l][j]++;
                    }
                }
            }
        }
    }
    // 행 검사
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - k + 1; j++) {
            if (!board[i][j + k - 1]) {
                continue;
            }
            // 행으로 세기
            if (board[i][j] && !visited[i][j][0]) {
                bool chk = true;
                for (int l = j; l < j + k; l++) {
                    if (!board[i][l]) {
                        chk = false;
                        break;
                    }
                }
                if (chk) {
                    visited[i][j][0] = true;
                    seeds++;
                    for (int l = j; l < j + k; l++) {
                        board[i][l]++;
                    }
                }
            }
            if (seeds == 2) {
                break;
            }
        }
    }
    //완전히 중복
    if (seeds == 1) {
        cout << k << '\n';
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 2) {
                    cout << i + 1 << ' ' << j + 1 << '\n';
                }
            }
        }
        return 0;
    }
    int ans = 0;
    vector<pair<int, int>> result;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
//            cout << board[i][j] << ' ';
            if (board[i][j] == 3) {
                ans++;
                result.push_back({i + 1, j + 1});
            }
        }
//        cout << '\n';
    }
    cout << ans << '\n';
    for (int i = 0; i < result.size(); i++) {
        cout << result[i].first << " " << result[i].second << '\n';
    }
    return 0;
}