//
// Created by cse_asus on 2022-12-15.
//

#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> ci;

// bfs
int bfs(int sz, int sx, int sy, int ex, int ey) {
    queue<ci> q;
    vector<vector<bool>> visited(sz, vector<bool>(sz, false));
    queue<int> num;

    int dx[8] = {-1, -1, -2, -2, 1, 1, 2, 2};
    int dy[8] = {2, -2, 1, -1, 2, -2, 1, -1};

    q.push({sx, sy});
    num.push(0);
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        int n = num.front();
        q.pop();
        num.pop();
        if (x == ex && y == ey) {
            return n;
        }
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= sz || ny < 0 || ny >= sz || visited[nx][ny]) {
                continue;
            }
            visited[nx][ny] = true;
            q.push({nx, ny});
            num.push(n + 1);
        }
    }
}

int main() {
    int t, n, sx, sy, ex, ey;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> sx >> sy >> ex >> ey;

        cout << bfs(n, sx, sy, ex, ey) << '\n';
    }
    return 0;
}