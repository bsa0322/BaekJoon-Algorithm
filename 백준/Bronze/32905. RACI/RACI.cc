#include <iostream>
#include <vector>

using namespace std;

bool validateChart(int &r, int &c, vector<vector<char>> &chart) {
    for (int i = 0; i < r; i++) {
        bool flag = false;
        for (int j = 0; j < c; j++) {
            if (flag && chart[i][j] == 'A') {
                return false;
            }
            if (chart[i][j] == 'A') {
                flag = true;
            }
        }
        if (!flag) {
            return false;
        }
    }
    return true;
}

/**
 * A가 각 라인마다 정확히 1개 존재하는지 확인
 */
int main() {
    int r, c;
    cin >> r >> c;
    vector<vector<char>> chart(r, vector<char>(c, '\0'));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> chart[i][j];
        }
    }

    cout << (validateChart(r, c, chart) ? "Yes" : "No");
    return 0;
}