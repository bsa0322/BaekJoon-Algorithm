#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pi;

vector<vector<int>> getMinimumDist(pi start, int &n) {
    vector<vector<int>> check(n, vector<int>(n, 0)); // 최소 이동 횟수
    queue<pi> q;

    // 방향 배열
    int dr[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dc[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

    // 시작 위치 초기화
    q.push(start);
    check[start.first][start.second] = 1;
    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        int d = check[cr][cc];
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || check[nr][nc]) {
                continue;
            }
            q.push({nr, nc});
            check[nr][nc] = d + 1;
        }
    }
    return check;
}

/**
 * BFS 한 번만 돌려서 모든 좌표에 대해 최소 이동 횟수 미리 구하기
 *
 * !! 주의 !! 상대 위치마다 BFS 돌리면 시간초과 -> 연산 횟수: 1000 * 500 * 500 = 250000000
 */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, x, y, a, b;
    cin >> n >> m >> x >> y;

    vector<vector<int>> dist = getMinimumDist({x - 1, y - 1}, n);
    while (m--) {
        cin >> a >> b;
        cout << dist[a - 1][b - 1] - 1 << ' ';
    }
    return 0;
}