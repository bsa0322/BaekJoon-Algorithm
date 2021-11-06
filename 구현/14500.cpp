#include<iostream>

using namespace std;

int main() {
    long long num[1001][1001] = {0,};
    long long answer;
    int n, m, i, j;
    cin >> n >> m;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            cin >> num[i][j];
        }
    }
    //테트로미노 다 놓아보기 ... 완전 노가다.. ^!^
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (answer < num[i][j] + num[i + 1][j] + num[i + 2][j] + num[i + 2][j - 1]) {
                answer = num[i][j] + num[i + 1][j] + num[i + 2][j] + num[i + 2][j - 1];
            }
            if (answer < num[i][j] + num[i + 1][j] + num[i + 1][j - 1] + num[i + 2][j - 1]) {
                answer = num[i][j] + num[i + 1][j] + num[i + 1][j - 1] + num[i + 2][j - 1];
            }
            if (answer < num[i][j] + num[i][j + 1] + num[i + 1][j] + num[i + 1][j - 1]) {
                answer = num[i][j] + num[i][j + 1] + num[i + 1][j] + num[i + 1][j - 1];
            }
            if (answer < num[i][j] + num[i + 1][j - 1] + num[i + 1][j] + num[i + 1][j + 1]) {
                answer = num[i][j] + num[i + 1][j - 1] + num[i + 1][j] + num[i + 1][j + 1];
            }
            if (answer < num[i][j] + num[i + 1][j] + num[i + 1][j - 1] + num[i + 2][j]) {
                answer = num[i][j] + num[i + 1][j] + num[i + 1][j - 1] + num[i + 2][j];
            }
            if (answer < num[i][j] + num[i][j + 1] + num[i][j + 2] + num[i - 1][j + 2]) {
                answer = num[i][j] + num[i][j + 1] + num[i][j + 2] + num[i - 1][j + 2];
            }
            if (answer < num[i][j] + num[i][j + 1] + num[i][j + 2] + num[i][j + 3]) {
                answer = num[i][j] + num[i][j + 1] + num[i][j + 2] + num[i][j + 3];
            }
            if (answer < num[i][j] + num[i + 1][j] + num[i + 2][j] + num[i + 3][j]) {
                answer = num[i][j] + num[i + 1][j] + num[i + 2][j] + num[i + 3][j];
            }
            if (answer < num[i][j] + num[i][j + 1] + num[i + 1][j] + num[i + 1][j + 1]) {
                answer = num[i][j] + num[i][j + 1] + num[i + 1][j] + num[i + 1][j + 1];
            }
            if (answer < num[i][j] + num[i + 1][j] + num[i + 2][j] + num[i + 2][j + 1]) {
                answer = num[i][j] + num[i + 1][j] + num[i + 2][j] + num[i + 2][j + 1];
            }
            if (answer < num[i][j] + num[i][j + 1] + num[i][j + 2] + num[i + 1][j + 2]) {
                answer = num[i][j] + num[i][j + 1] + num[i][j + 2] + num[i + 1][j + 2];
            }
            if (answer < num[i][j] + num[i + 1][j] + num[i + 1][j + 1] + num[i + 1][j + 2]) {
                answer = num[i][j] + num[i + 1][j] + num[i + 1][j + 1] + num[i + 1][j + 2];
            }
            if (answer < num[i][j] + num[i + 1][j] + num[i][j + 1] + num[i][j + 2]) {
                answer = num[i][j] + num[i + 1][j] + num[i][j + 1] + num[i][j + 2];
            }
            if (answer < num[i][j] + num[i][j + 1] + num[i + 1][j + 1] + num[i + 2][j + 1]) {
                answer = num[i][j] + num[i][j + 1] + num[i + 1][j + 1] + num[i + 2][j + 1];
            }
            if (answer < num[i][j] + num[i + 1][j] + num[i + 2][j] + num[i][j + 1]) {
                answer = num[i][j] + num[i + 1][j] + num[i + 2][j] + num[i][j + 1];
            }
            if (answer < num[i][j] + num[i + 1][j] + num[i + 1][j + 1] + num[i + 2][j + 1]) {
                answer = num[i][j] + num[i + 1][j] + num[i + 1][j + 1] + num[i + 2][j + 1];
            }
            if (answer < num[i][j] + num[i][j + 1] + num[i + 1][j + 1] + num[i + 1][j + 2]) {
                answer = num[i][j] + num[i][j + 1] + num[i + 1][j + 1] + num[i + 1][j + 2];
            }
            if (answer < num[i][j] + num[i][j + 1] + num[i][j + 2] + num[i + 1][j + 1]) {
                answer = num[i][j] + num[i][j + 1] + num[i][j + 2] + num[i + 1][j + 1];
            }
            if (answer < num[i][j] + num[i + 1][j] + num[i + 2][j] + num[i + 1][j + 1]) {
                answer = num[i][j] + num[i + 1][j] + num[i + 2][j] + num[i + 1][j + 1];
            }
        }
    }
    cout << answer << '\n';
    return 0;
}
