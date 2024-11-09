#include <iostream>
#include <vector>

using namespace std;
const int ALPHA = 26;

/**
 * 입력이 최대 200,000 들어올 수 있으므로 입출력 속도 향상 써야 하는 문제 !!
 */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;

    cin >> s;
    int n = s.length();

    int q, l, r;
    char c;
    cin >> q;

    // 누적합 미리 구해놓기
    vector<vector<int>> sum(n + 1, vector<int>(ALPHA, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < ALPHA; j++) {
            sum[i][j] += sum[i - 1][j];
            if (s[i - 1] - 'a' == j) {
                sum[i][j]++;
            }
        }
    }

    while (q--) {
        cin >> c >> l >> r;
        cout << sum[r + 1][c - 'a'] - sum[l][c - 'a'] << '\n';
    }
    return 0;
}