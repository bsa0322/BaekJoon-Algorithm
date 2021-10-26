#include <iostream>
#include <vector>

using namespace std;

void floyd(int n, vector<vector<int>> &matrix) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (i == k || matrix[i][k] == -1)
                continue;
            for (int j = 1; j <= n; j++) {
                if (j == k || i == j || matrix[k][j] == -1)
                    continue;
                if (matrix[i][j] == -1 || matrix[i][j] > matrix[i][k] + matrix[k][j])
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
            }
        }
    }
}

int main() {
    int n, m, x, a, b, c;

    //입력
    cin >> n >> m >> x;
    vector<vector<int>> matrix(n + 1, vector<int>(n + 1, -1));
    while (m--) {
        cin >> a >> b >> c;
        matrix[a][b] = c;
    }
    for (int i = 1; i <= n; i++)
        matrix[i][i] = 0;

    floyd(n, matrix);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int d1 = matrix[i][x];
        int d2 = matrix[x][i];
        ans = max(d1 + d2, ans);
    }
    cout << ans << '\n';

    return 0;
}