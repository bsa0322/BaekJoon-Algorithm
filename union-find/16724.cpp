#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board, visited;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
bool is_cycle = false;

void dfs(int r, int c, int t) {
    if (visited[r][c] == t) {
        is_cycle = true;
        return;
    } else if (visited[r][c])
        return;

    visited[r][c] = t;
    int d = board[r][c];
    dfs(r + dr[d], c + dc[d], t);
}

/**
 * 방향정보가 반복되는 구간(싸이클) 개수 찾기 -> 몇 개 집합인지 찾기
 */

int main() {
    string s;
    int n, m;

    //입력
    cin >> n >> m;
    board.assign(n, vector<int>(m, 0));
    visited.assign(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < s.length(); j++) {
            if (s[j] == 'D') //하
                board[i][j] = 1;
            else if (s[j] == 'L') //좌
                board[i][j] = 2;
            else if (s[j] == 'R') //우
                board[i][j] = 3;
        }
    }

    int ans = 0, cnt = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                is_cycle = false;
                dfs(i, j, cnt++);
                if (is_cycle)
                    ans++;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}