#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 50;

vector<vector<vector<int>>> dp;

int w(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return 1;
    }
    if (dp[a][b][c]) {
        return dp[a][b][c];
    }
    if (a > 20 || b > 20 || c > 20) {
        return dp[a][b][c] = w(20, 20, 20);
    }
    if (a < b && b < c) {
        return dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    }
    return dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main() {
    dp.assign(SIZE + 1, vector<vector<int>>(SIZE + 1, vector<int>(SIZE + 1, 0)));
    int a, b, c;
    while (cin >> a >> b >> c) {
        if (a == -1 && b == -1 && c == -1) {
            break;
        }
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
    }
    return 0;
}