#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

string s[1001];
int board[1001][1001];
int table[1001][1001];

int main() {
    int answer = 0;
    int n, m;

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            board[i][j + 1] = (s[i][j] - '0');
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (board[i][j]) {
                table[i][j] = min(min(table[i - 1][j], table[i][j - 1]), table[i - 1][j - 1]) + 1;
            }
            answer = max(answer, table[i][j]);
        }
    }

    answer = answer * answer;

    cout << answer << '\n';
}