#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci;

int n, m, tot_cnt, sz, sub_cnt; //cctv 설치한 토탈 수, cctv 사이즈
vector<vector<int>> board;
vector<pair<int, ci>> cctv;
vector<vector<bool>> d;

vector<vector<vector<bool>>> cctv_d = {{{0, 0, 0, 0}},
                                       {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}},
                                       {{0, 1, 0, 1}, {1, 0, 1, 0}},
                                       {{1, 0, 0, 1}, {0, 0, 1, 1}, {0, 1, 1, 0}, {1, 1, 0, 0}},
                                       {{0, 1, 1, 1}, {1, 0, 1, 1}, {1, 1, 0, 1}, {1, 1, 1, 0}},
                                       {{1, 1, 1, 1}}};

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, -1, 0, 1};

int cnt_board(int r, int c, vector<bool> t, vector<vector<bool>> &check) {
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        if (t[i]) {
            int nr = r;
            int nc = c;
            while (true) {
                nr += dr[i];
                nc += dc[i];
                if (nr < 0 || nc < 0 || nr >= n || nc >= m || board[nr][nc] == 6) break;
                if (!board[nr][nc] && !check[nr][nc]) {
                    check[nr][nc] = true;
                    cnt++;
                }
            }
        }
    }
    return cnt;
}

int installCctv() {
    vector<vector<bool>> check(n, vector<bool>(m, 0));
    int cnt = 0;
    for (int i = 0; i < sz; i++) {
        int r = cctv[i].second.first;
        int c = cctv[i].second.second;
        cnt += cnt_board(r, c, d[i], check);
    }
    return cnt;
}

void backtracking(int cnt) {
    if (cnt == sz) {
        int temp = installCctv();
        tot_cnt = max(tot_cnt, temp + sub_cnt);
        return;
    }
    for (int i = 0; i < cctv_d[cctv[cnt].first].size(); i++) {
        d[cnt] = cctv_d[cctv[cnt].first][i];
        backtracking(cnt + 1);
        d[cnt] = {0, 0, 0, 0};
    }
}

int main() {
    cin >> n >> m;
    board.assign(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j]) {
                sub_cnt++;
                if (board[i][j] != 6)
                    cctv.push_back(make_pair(board[i][j], ci(i, j)));
            }
        }
    }

    sz = cctv.size();
    d.assign(sz, {}); //각각 cctv마다 방향
    backtracking(0);

    cout << n * m - tot_cnt << '\n';
    return 0;
}