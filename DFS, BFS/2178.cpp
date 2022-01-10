#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
typedef pair<ci, int> cc;

int main() {
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int n, m;
    string s;

    //입력
    cin >> n >> m;
    vector<vector<int>> maze(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            maze[i][j] = s[j] - '0';
        }
    }

    //연산
    int ans = 0;
    queue<cc> q;
    q.push(cc(ci(0, 0), 1));
    while (!q.empty()) {
        cc t = q.front();
        q.pop();
        int x = t.first.first;
        int y = t.first.second;
        int c = t.second;
        if (x == n - 1 && y == m - 1) {
            ans = c;
            break;
        }
        for (int i = 0; i < 4; i++) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (tx >= 0 && tx < n && ty >= 0 && ty < m && maze[tx][ty]) {
                maze[tx][ty] = 0;
                q.push(cc(ci(tx, ty), c + 1));
            }
        }
    }

    //출력
    cout << ans;

    return 0;
}