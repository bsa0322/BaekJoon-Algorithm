#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pi;
const int SIZE = 3;

string first_seed = ""; // 정답
string temp_seed = "";
vector<bool> check;

bool validateRow(int &r, vector<vector<bool>> &check_board) {
    return check_board[r][0] && check_board[r][1] && check_board[r][2];
}

bool validateColumn(int &c, vector<vector<bool>> &check_board) {
    return check_board[0][c] && check_board[1][c] && check_board[2][c];
}

bool validateDialog(int &r, int &c, vector<vector<bool>> &check_board) {
    bool flag = false;
    if (r == 0 && c == 0) {
        flag = true;
    }
    if (r == 1 && c == 1) {
        flag = true;
    }
    if (r == 2 && c == 2) {
        flag = true;
    }
    return flag && check_board[0][0] && check_board[1][1] && check_board[2][2];
}

bool validateOpDialog(int &r, int &c, vector<vector<bool>> &check_board) {
    bool flag = false;
    if (r == 0 && c == 2) {
        flag = true;
    }
    if (r == 1 && c == 1) {
        flag = true;
    }
    if (r == 2 && c == 0) {
        flag = true;
    }
    return flag && check_board[0][2] && check_board[1][1] && check_board[2][0];
}

string getScoreStr(string &s, vector<pi> &pos, vector<string> &board) {
    string ans = "";
    vector<vector<bool>> check_board(SIZE, vector<bool>(SIZE, false));
    vector<bool> check_col(SIZE, false);
    vector<bool> check_row(SIZE, false);
    vector<bool> check_dialog(2, false);
    for (int i = 0; i < s.length(); i++) {
        int score = 0;
        int r = pos[i].first;
        int c = pos[i].second;
        check_board[r][c] = true;
        if (validateRow(r, check_board) && !check_row[r]) {
            check_row[r] = true;
            score++;
        }
        if (validateColumn(c, check_board) && !check_col[c]) {
            check_col[c] = true;
            score++;
        }
        if (validateDialog(r, c, check_board) && !check_dialog[0]) {
            check_dialog[0] = true;
            score++;
        }
        if (validateOpDialog(r, c, check_board) && !check_dialog[1]) {
            check_dialog[1] = true;
            score++;
        }
        ans += to_string(score);
    }
    return ans;
}

void getFirstSeed(int cnt, string &s, string &score, vector<string> &board) {
    if (cnt == SIZE * SIZE) {
        vector<pi> pos(SIZE * SIZE);
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                int idx = temp_seed.find(board[i][j]);
                pos[idx] = {i, j};
            }
        }
        string temp_score = getScoreStr(temp_seed, pos, board);
        if (temp_score == score) {
            first_seed = temp_seed;
        }
        return;
    }

    for (int i = 0; i < SIZE * SIZE; i++) {
        if (!check[i]) {
            check[i] = true;
            temp_seed[cnt] = s[i];
            getFirstSeed(cnt + 1, s, score, board);
            check[i] = false;
            if (first_seed != "") {
                // 정답 찾음
                return;
            }
        }
    }
}

/**
 * 점수 문자열 구한 후, 점수 문자열과 일치하는 시드 문자열 중 사전순으로 가장 앞에 있는 문자열 구하기
 * (0, 0) (0, 1) (0, 2)
 * (1, 0) (1, 1) (1, 2)
 * (2, 0) (2, 1) (2, 2)
 * 주 대각선: 뺀 값이 0
 * 반 대각선: 더한 값이 2
 */
int main() {
    int t;
    string s;
    vector<string> board(SIZE);
    vector<pi> pos(SIZE * SIZE);

    cin >> t;
    while (t--) {
        cin >> s;
        for (int i = 0; i < SIZE; i++) {
            cin >> board[i];
            for (int j = 0; j < SIZE; j++) {
                int idx = s.find(board[i][j]);
                pos[idx] = {i, j};
            }
        }

        first_seed = "";
        temp_seed.assign(SIZE * SIZE, '0');
        check.assign(SIZE * SIZE, false);
        string score_lst = getScoreStr(s, pos, board);
        sort(s.begin(), s.end());

        // 사전순 가장 앞에 있는 시드 문자열 구하기
        getFirstSeed(0, s, score_lst, board);
        cout << score_lst << ' ' << first_seed << '\n';
    }
    return 0;
}