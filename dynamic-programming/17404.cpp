#include <iostream>

using namespace std;

int num[1001][3];
int table[1001][3][3]; //1: 집: / 2: r,g,b / 3: 1번 집 고정 r,g,b

int main() {
    int n;

    //입력
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> num[i][j];
        }
    }

    int ans = 0;
    //연산
    for (int i = 0; i < 3; i++) {
        table[1][i][i] = num[1][i];
        for (int j = 2; j < n; j++) {
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    if (k == l) continue;
                    if (table[j - 1][l][i] == 0) continue;
                    if (table[j][k][i] == 0 || table[j][k][i] > table[j - 1][l][i] + num[j][k])
                        table[j][k][i] = table[j - 1][l][i] + num[j][k];
                }
            }
        }
        for (int j = 0; j < 3; j++) { //n번째
            if (i != j) {
                for (int k = 0; k < 3; k++) {
                    if (j == k) continue;
                    if (table[n - 1][k][i] == 0) continue;
                    if (table[n][j][i] == 0 || table[n][j][i] > table[n - 1][k][i] + num[n][j])
                        table[n][j][i] = table[n - 1][k][i] + num[n][j];
                }
                if (table[n][j][i] && (ans == 0 || ans > table[n][j][i]))
                    ans = table[n][j][i];
            }
        }
    }

    //출력
    cout << ans << '\n';

    /*
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            cout << table[i][j][0] << ' ';
        }
        cout << '\n';
    }
    */

    return 0;
}