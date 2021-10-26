//저울(10159)와 유사한 문제
#include <iostream>
#include <vector>

using namespace std;

void floyd(int n, vector<vector<bool>> &matrix) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (i == k || !matrix[i][k])
                continue;
            for (int j = 1; j <= n; j++) {
                if (j == k || i == j || !matrix[k][j])
                    continue;
                matrix[i][j] = true;
            }
        }
    }
}

int main() {
    int n, k, s, a, b;

    cin >> n >> k;
    vector<vector<bool>> matrix(n + 1, vector<bool>(n + 1, 0));
    while (k--) {
        cin >> a >> b;
        matrix[a][b] = true;
    }
    for (int i = 1; i <= n; i++)
        matrix[i][i] = true;

    floyd(n, matrix);
    cin >> s;
    while (s--) {
        cin >> a >> b;
        if (matrix[a][b])
            cout << "-1\n";
        else if (matrix[b][a])
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}