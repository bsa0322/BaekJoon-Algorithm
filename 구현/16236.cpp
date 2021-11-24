#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
typedef pair<int, ci> cc;

struct cmp {
    bool operator()(cc a, cc b) {
        if (a.first != b.first)
            return a.first > b.first;
        if(a.second.first != b.second.first)
            return a.second.first > b.second.first;
        return a.second.second > b.second.second;
    }
};

int bfs(int n, int r, int c, int cnt, int cur_size, int t, vector<vector<int>> &board) {
    int dr[4] = {-1, 0, 0, 1};
    int dc[4] = {0, -1, 1, 0};

    vector<vector<int>> visited(n, vector<int>(n, -1));
    queue<ci> q;
    priority_queue<cc, vector<cc>, cmp> pq; //먹을 수 있는 아기상어 나열

    q.push({r, c});
    visited[r][c] = t;
    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        if (board[cr][cc] && board[cr][cc] < cur_size)
            pq.push({visited[cr][cc], {cr, cc}});

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || visited[nr][nc] != -1 || board[nr][nc] > cur_size)
                continue;
            q.push({nr, nc});
            visited[nr][nc] = visited[cr][cc] + 1;
        }
    }

    if (pq.empty())
        return t;

    int cr = pq.top().second.first;
    int cc = pq.top().second.second;
    board[cr][cc] = 0;
    if (cnt + 1 == cur_size)
        return bfs(n, cr, cc, 0, cur_size + 1, visited[cr][cc], board);
    else
        return bfs(n, cr, cc, cnt + 1, cur_size, visited[cr][cc], board);
}

/**
 * 위->왼 순서로 bfs 탐색
 * 가장 가까운 거리에 있는 물고기(아기 상어보다 크기 작은)
 *
 * 위->왼->오->하, 순으로 탐색하면 ..... 오른쪽이 더 가까운 경우를 거르지 못함
 * => 그냥 현재 자리에서 먹을 수 있는 모든 물고기 찾은 후에 가장 가까운 거(위,왼) 찾고, 거기서 다시 bfs 돌리고 .... 그렇게 하자 ...
 */

int main() {
    int n, r, c;

    //입력
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 9) {
                board[i][j] = 0;
                r = i;
                c = j;
            }
        }
    }

    cout << bfs(n, r, c, 0, 2, 0, board);
    return 0;
}