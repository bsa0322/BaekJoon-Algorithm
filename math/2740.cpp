#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
vector<vector<int>> mat_a, mat_b;

int main() {
    cin >> n >> m;
    mat_a.assign(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat_a[i][j];
        }
    }
    cin >> m >> k;
    mat_b.assign(m, vector<int>(k));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            cin >> mat_b[i][j];
        }
    }

    // 행렬의 곱 구하기
    vector<vector<int>> ans(n, vector<int>(k, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            for (int l = 0; l < m; l++) {
                ans[i][j] += mat_a[i][l] * mat_b[l][j];
            }
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}