#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> getSign(int &n) {
    vector<vector<char>> sign(n, vector<char>(n, ' '));
    for (int i = 0; i < n; i++) {
        sign[0][i] = sign[n - 1][i] = '*';
    }
    for (int i = 1; i < (n + 1) / 2; i++) {
        sign[i][0] = sign[n - i - 1][0] = sign[i][n - 1] = sign[n - i - 1][n - 1] = '*';
        sign[i][i] = sign[n - i - 1][i] = sign[i][n - i - 1] = sign[n - i - 1][n - i - 1] = '*';
    }
    return sign;
}

int main() {
    int n;
    cin >> n;

    vector<vector<char>> sign = getSign(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << sign[i][j];
        }
        cout << '\n';
    }
    return 0;
}