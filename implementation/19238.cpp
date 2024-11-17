#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;

vector<ci> end_point;

bool cmp(const pair<ci, int> &a, const pair<ci, int> &b) {
    if (a.second != b.second)
        return a.second < b.second;
    if (a.first.first != b.first.first)
        return a.first.first < b.first.first;
    return a.first.second < b.first.second;
}

vector<pair<ci, int>> bfs(bool start, int n, int r, int c, vector<vector<int>> &board) {
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    vector<vector<int>> visited(n, vector<int>(n, -1));
    vector<pair<ci, int>> people;
    queue<ci> q;

    q.push({r, c});
    visited[r][c] = 0;

    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        if (start && board[cr][cc] > 1) { //시작지점
            people.push_back({{cr, cc}, visited[cr][cc]});
        }
        if (!start && cr == end_point[board[r][c]].first && cc == end_point[board[r][c]].second) { //도착지점
            people.clear();
            people.push_back({{cr, cc}, visited[cr][cc]});
        }

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || board[nr][nc] == 1 || visited[nr][nc] != -1)
                continue;
            q.push({nr, nc});
            visited[nr][nc] = visited[cr][cc] + 1;
        }
    }
    return people;
}

int simulation(int n, int m, int init, int r, int c, vector<vector<int>> &board) {
    while (m--) {
        vector<pair<ci, int>> people = bfs(true, n, r, c, board);
//        for (int i = 0; i < people.size(); i++)
//            cout << people[i].first.first << ',' << people[i].first.second << ':' << people[i].second << ' ';
//        cout << '\n';
        if (people.empty())
            return -1;
        sort(people.begin(), people.end(), cmp); //가장 인접한 손님 찾기
        pair<ci, int> start = people[0];
        int fuel = start.second;
        if (init - fuel < 0)
            return -1;
        init -= fuel;
        people = bfs(false, n, start.first.first, start.first.second, board);
//        for (int i = 0; i < people.size(); i++)
//            cout << people[i].first.first << ',' << people[i].first.second << ',' << people[i].second << ' ';
//        cout << '\n';
        if (people.empty()) //도착지점에 도달하지 못하는 경우
            return -1;
        pair<ci, int> end = people[0];
        fuel = end.second;
        if (init - fuel < 0)
            return -1;
        init -= fuel;
        board[start.first.first][start.first.second] = 0;
        init += fuel * 2;
        r = end.first.first;
        c = end.first.second;
//        cout << "=====================\n";
    }
    return init;
}

int main() {
    int n, m, init, r, c, sr, sc, er, ec;

    cin >> n >> m >> init;
    vector<vector<int>> board(n, vector<int>(n, 0));
    end_point.assign(m + 2, {-1, -1});
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    cin >> r >> c;
    for (int i = 2; i < m + 2; i++) { //벽이 1이니, 손님 정보 2부터
        cin >> sr >> sc >> er >> ec;
        board[sr - 1][sc - 1] = i;
        end_point[i] = {er - 1, ec - 1};
    }
    cout << simulation(n, m, init, r - 1, c - 1, board);
}