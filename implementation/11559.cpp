#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
const int ROW = 12;
const int COL = 6;

bool bfs(int r, int c, vector<vector<char>> &board, vector<vector<bool>> &check) {
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    queue<ci> q;
    vector<vector<bool>> visited(ROW, vector<bool>(COL, false));
    //시작 초기화
    q.push({r, c});
    visited[r][c] = true;
    int cnt = 1;
    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if (nr < 0 || nr >= ROW || nc < 0 || nc >= COL || visited[nr][nc]) {
                continue;
            }
            if (board[nr][nc] == board[cr][cc]) {
                q.push({nr, nc});
                visited[nr][nc] = true;
                check[nr][nc] = true;
                cnt++;
            }
        }
    }
    if (cnt >= 4) { //뿌요 터짐
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                if (visited[i][j]) {
                    board[i][j] = '.';
                }
            }
        }
        return true;
    }
    return false;
}

//뿌요 아래로 내리기
void down(vector<vector<char>> &board) {
    for (int j = 0; j < COL; j++) {
        for (int i = ROW - 1; i > 0; i--) {
            if (board[i][j] == '.') {
                //.이 아닌 곳 찾기
                int pos = i;
                for (int k = i - 1; k >= 0; k--) {
                    if (board[k][j] != '.') {
                        pos = k;
                        break;
                    }
                }
                for (int k = i; k > 0; k--) {
                    if(k-(i-pos) >= 0){
                        board[k][j] = board[k - (i - pos)][j];
                    }
                }
                board[pos][j] = '.';
            }
        }
    }
}

void print(vector<vector<char>> &board) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }
}

int simulation(vector<vector<char>> &board) {
    int answer = 0;
    while (true) {
        bool chk = false; //뿌요 터지는지 확인
        vector<vector<bool>> check(ROW, vector<bool>(COL, false));
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                if (board[i][j] != '.' && !check[i][j]) {
                    check[i][j] = true;
                    if (bfs(i, j, board, check)) { //한 번이라도 뿌요 터진다면
                        chk = true;
                    }
                }
            }
        }
        print(board);
        if (!chk) { //뿌요 안터졌다면
            break;
        }
        down(board);
        print(board);
        answer++;
    }
    return answer;
}

/**
 * [뿌요뿌요]
 *
 * 1. 뿌요 터뜨리기
 * 2. 뿌요 아래로 내리기
 */

int main() {
    //입력
    vector<vector<char>> board(ROW, vector<char>(COL));
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            cin >> board[i][j];
        }
    }

    //연산 & 출력
    cout << simulation(board);
    return 0;
}