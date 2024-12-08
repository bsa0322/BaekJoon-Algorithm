#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 9;

int getScore(int &x, int &n, vector<vector<int>> &lines) {
    int score = 0;
    for (int j = 0; j < SIZE; j++) {
        bool is_long = false; // 롱 노트인지 확인
        // 아래부터 확인하면서 롱 노트 구간 모두 2 로 바꾸기
        for (int i = n - 1; i >= 0; i--) {
            if (lines[i][j] == 0) {
                is_long = false;
                continue;
            }
            if (!is_long && lines[i][j] == 2 && (i == n - 1 || lines[i + 1][j] != 1) &&
                (i == 0 || lines[i - 1][j] != 0)) {
                // 롱 노트라면
                is_long = true;
                score += 80;
            } else if (is_long && lines[i][j] == 1) {
                lines[i][j] = 2;
            } else if (is_long && lines[i][j] == 2) {
                // 롱 노트 끝
                is_long = false;
            }
        }
        is_long = false;
        // 롱 노트의 끝만 나오는 경우 다시 탐색
        for (int i = 0; i < n; i++) {
            if (lines[i][j] == 0) {
                is_long = false;
                continue;
            }
            if (!is_long && lines[i][j] == 2) {
                // 롱 노트 끝
                is_long = true;
            } else if (is_long && lines[i][j] == 1) {
                lines[i][j] = 2;
            }
        }
    }
    // 최종 점수 계산
    for (int j = 0; j < SIZE; j++) {
        int long_cnt = 0;
        for (int i = 0; i < n; i++) {
            if (lines[i][j] == 2) {
                // 롱 노트 카운트
                long_cnt++;
                continue;
            }
            // 롱 노트 기록 보고 점수 계산
            if (long_cnt > 0) {
                // 점수 계산
                int long_score = (x * long_cnt * 24) / 144;
                score += long_score;
                long_cnt = 0;
            }
            if (lines[i][j] == 1) {
                score += 100;
            }
        }
        // 롱 노트 기록 보고 점수 계산
        if (long_cnt > 0) {
            // 점수 계산
            int long_score = (x * long_cnt * 24) / 144;
            score += long_score;
        }
    }
    return score;
}

int main() {
    int b, x, n;
    cin >> b >> x >> n;
    vector<vector<int>> lines(n, vector<int>(SIZE, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < SIZE; j++) {
            cin >> lines[i][j];
        }
    }

    cout << getScore(x, n, lines);
    return 0;
}