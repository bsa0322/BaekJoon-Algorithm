#include <iostream>
#include <queue>
#include <map>

using namespace std;
typedef pair<int, int> pi;
typedef pair<pi, pi> ppi;

int n, m;

int boardStringIdx(int &r, int &c) {
    return (r * m) + c;
}

// pos = {-1, -1} 구슬에 빠진 상태 !!
string movingOneBead(int &direc, string &board, pi &pos, bool is_red) {
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    string new_board = board;
    pi new_pos = {pos.first + dr[direc], pos.second + dc[direc]};
    while (true) {
        int idx = boardStringIdx(new_pos.first, new_pos.second);
        if (board[idx] == 'O') {
            new_pos = {-1, -1};
            break;
        } else if (board[idx] == '#' || (is_red && board[idx] == 'B') || (!is_red && board[idx] == 'R')) {
            new_pos = {new_pos.first - dr[direc], new_pos.second - dc[direc]};
            break;
        }
        new_pos = {new_pos.first + dr[direc], new_pos.second + dc[direc]};
    }
    int origin_idx = boardStringIdx(pos.first, pos.second);
    new_board[origin_idx] = '.';
    if (new_pos.first != -1) {
        int new_idx = boardStringIdx(new_pos.first, new_pos.second);
        new_board[new_idx] = (is_red ? 'R' : 'B');
    }
    pos = new_pos;
    return new_board;
}

// 구슬 - 상, 하, 좌, 우로 움직이기
string movingTwoBead(int &direc, string &board, pi &red, pi &blue) {
    bool is_red_first = true; // default: red 먼저
    switch (direc) {
        case 0:
            // 상
            if (red.first > blue.first) {
                is_red_first = false;
            }
            break;
        case 1:
            // 하
            if (red.first < blue.first) {
                is_red_first = false;
            }
            break;
        case 2:
            if (red.second > blue.second) {
                is_red_first = false;
            }
            // 좌
            break;
        case 3:
            // 우
            if (red.second < blue.second) {
                is_red_first = false;
            }
            break;
        default:
            break;
    }

    if (is_red_first) {
        string new_board = movingOneBead(direc, board, red, true);
        return movingOneBead(direc, new_board, blue, false);
    } else {
        string new_board = movingOneBead(direc, board, blue, false);
        return movingOneBead(direc, new_board, red, true);
    }
}

int removeRedBead(string &board, pi &red, pi &blue) {
    map<string, bool> check;
    queue<ppi> q;
    queue<string> q_board;
    queue<int> q_cnt;
    queue<int> q_direc;

    check[board] = true;
    q.push({red, blue});
    q_board.push(board);
    q_cnt.push(0);
    q_direc.push(-1);

    while (!q.empty()) {
        pi cur_red = q.front().first;
        pi cur_blue = q.front().second;
        string cur_board = q_board.front();
        int cur_cnt = q_cnt.front();
        int prev_direc = q_direc.front();
        q.pop();
        q_board.pop();
        q_cnt.pop();
        q_direc.pop();

//        cout << "현재 빨간: {" << cur_red.first << ',' << cur_red.second << "}\n";
//        cout << "현재 파란: {" << cur_blue.first << ',' << cur_blue.second << "}\n";
//        cout << "현재 board: " << cur_board << '\n';
//        cout << "현재 cnt: " << cur_cnt << '\n';
//        cout << "이전 방향: " << prev_direc << "\n================\n";

        // 빨간 구슬만 빠졌다면
        if (cur_red.first == -1 && cur_blue.first != -1) {
            return cur_cnt;
        }
        // 둘 다 빠짐 or 파란 구슬이 빠졌다면 넘어감
        if ((cur_red.first == -1 && cur_blue.first == -1) || cur_blue.first == -1) {
            continue;
        }

        for (int i = 0; i < 4; i++) {
            pi new_red = cur_red;
            pi new_blue = cur_blue;
            string new_board = movingTwoBead(i, cur_board, new_red, new_blue);
            if (!check[new_board]) {
                check[new_board] = true;
                q.push({new_red, new_blue});
                q_board.push(new_board);
                q_cnt.push(cur_cnt + 1);
                q_direc.push(i);
            }
        }
    }
    return -1;
}

int main() {
    pi red, blue;

    cin >> n >> m;
    string board, temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        board += temp;
        for (int j = 0; j < m; j++) {
            if (temp[j] == 'R') {
                red = {i, j};
            } else if (temp[j] == 'B') {
                blue = {i, j};
            }
        }
    }

    int cnt = removeRedBead(board, red, blue);
    cout << (cnt > 10 ? -1 : cnt);

    return 0;
}