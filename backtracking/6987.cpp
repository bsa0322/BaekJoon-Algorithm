#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> board;
vector<vector<bool>> check;
bool answer;

void backtracking(int team, int cnt) {
    if (team == 6) {
        answer = true;
        return;
    }
    if (cnt == 5) {
        backtracking(team + 1, 0);
        return;
    }

    if (!board[team][0] && !board[team][1] && !board[team][2]) {
        backtracking(team + 1, 0);
        return;
    }

    if (board[team][1]) {
        for (int i = 0; i < 6; i++) {
            if (!check[team][i] && board[i][1]) {
                check[team][i] = true;
                board[team][1]--;
                board[i][1]--;
                backtracking(team, cnt + 1);
                check[team][i] = false;
                board[team][1]++;
                board[i][1]++;
            }
        }
    } else if (board[team][0]) {
        for (int i = 0; i < 6; i++) {
            if (!check[team][i] && board[i][2]) {
                check[team][i] = true;
                board[team][0]--;
                board[i][2]--;
                backtracking(team, cnt + 1);
                check[team][i] = false;
                board[team][0]++;
                board[i][2]++;
            }
        }
    } else if (board[team][2]) {
        for (int i = 0; i < 6; i++) {
            if (!check[team][i] && board[i][0]) {
                check[team][i] = true;
                board[team][2]--;
                board[i][0]--;
                backtracking(team, cnt + 1);
                check[team][i] = false;
                board[team][2]++;
                board[i][0]++;
            }
        }
    }
}

/**
 * https://www.acmicpc.net/problem/6987
 * 백트래킹
 * 승, 무, 패 합이 5가 아닐 수도 있다.....!!!
 */

int main() {
    int test_case = 4;

    while (test_case--) {
        answer = false;
        board.assign(6, vector<int>(3, 0));
        check.assign(6, vector<bool>(6, false));

        bool is_not_five = false;
        for (int i = 0; i < 6; i++) {
            check[i][i] = true;
            int temp_sum = 0;
            for (int j = 0; j < 3; j++) {
                cin >> board[i][j];
                temp_sum += board[i][j];
            }
            if (temp_sum != 5) { // 승, 무, 패 합 5인지 확인
                is_not_five = true;
            }
        }

        if (!is_not_five) {
            backtracking(0, 0);
        }

        cout << answer << ' ';
    }
    return 0;
}