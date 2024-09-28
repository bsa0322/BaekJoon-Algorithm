#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;
typedef pair<int, int> pi;
typedef pair<pi, pi> ppi;


int getMinCnt(int &n, int &m, string &board, ppi &coin_pos) {
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    map<string, bool> check;

    queue<ppi> q; // 현재 동전 위치
    queue<int> qc; // 움직인 횟수 카운트
    queue<string> qs; // 현재 board 상황

    check[board] = true;
    q.push(coin_pos);
    qc.push(0);
    qs.push(board);

    while (!q.empty()) {
        pi coin1 = q.front().first;
        pi coin2 = q.front().second;
        int cnt = qc.front();
        string cur_board = qs.front();
        q.pop();
        qc.pop();
        qs.pop();

//        cout << "현재 상황 \n";
//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < m; j++) {
//                cout << cur_board[i * m + j];
//            }
//            cout << '\n';
//        }
//        cout << "===========\n";

        if (coin1.first == -1 && coin2.first == -1) {
            continue;
        }
        if ((coin1.first == -1 && coin2.first != -1) || (coin1.first != -1 && coin2.first == -1)) {
            return cnt;
        }

        for (int i = 0; i < 4; i++) {
            int nr1 = coin1.first + dr[i];
            int nc1 = coin1.second + dc[i];
            int nr2 = coin2.first + dr[i];
            int nc2 = coin2.second + dc[i];

            pi new_coin1 = {-1, -1};
            pi new_coin2 = {-1, -1};

            if (nr1 >= 0 && nr1 < n && nc1 >= 0 && nc1 < m) {
                if (board[nr1 * m + nc1] == '#') {
                    new_coin1 = coin1;
                } else {
                    new_coin1 = {nr1, nc1};
                }
            }
            if (nr2 >= 0 && nr2 < n && nc2 >= 0 && nc2 < m) {
                if (board[nr2 * m + nc2] == '#') {
                    new_coin2 = coin2;
                } else {
                    new_coin2 = {nr2, nc2};
                }
            }

            string new_board = cur_board;
            new_board[coin1.first * m + coin1.second] = '.';
            new_board[coin2.first * m + coin2.second] = '.';
            if (new_coin1.first != -1) {
                new_board[new_coin1.first * m + new_coin1.second] = 'o';
            }
            if (new_coin2.first != -1) {
                new_board[new_coin2.first * m + new_coin2.second] = 'o';
            }
            if (!check[new_board] || new_coin1.first == -1 || new_coin2.first == -1) {
                check[new_board] = true;
                q.push({new_coin1, new_coin2});
                qc.push(cnt + 1);
                qs.push(new_board);
            }
        }
    }

    return -1;
}

/**
 * https://www.acmicpc.net/problem/16197
 * 두 동전 중 하나만 보드에서 떨어뜨리기 위해 버튼을 최소 몇 번 눌러야 하는지
 * board 판을 애초에 string 으로 이어서 받은 후에, 인덱스 접근할 때 n 과 m 계산해서 접근하기
 * 체크 배열을 string 으로 이어서 set 으로 만들기
 *
 * string board 의 index = i * m + j
 *
 */

int main() {
    string board;
    int n, m;
    ppi coin_pos = {{-1, -1},
                    {-1, -1}};

    cin >> n >> m;
    vector<string> temp(n);
    for (int i = 0; i < n; i++) {
        cin >> temp[i];
        board += temp[i];
        for (int j = 0; j < m; j++) {
            if (temp[i][j] == 'o') {
                if (coin_pos.first.first == -1) {
                    coin_pos.first = {i, j};
                } else {
                    coin_pos.second = {i, j};
                }
            }
        }
    }

    int answer = getMinCnt(n, m, board, coin_pos);
    cout << (answer > 10 ? -1 : answer);

    return 0;
}