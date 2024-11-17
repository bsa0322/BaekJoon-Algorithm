#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pi;
const int MAX = 30000;

vector<int> getPath(int n, int m, vector<vector<pi>> &dp) {
    vector<int> result(m, 0);
    while (m--) {
        result[m] = n - dp[n][m + 1].second;
        n = dp[n][m + 1].second;
    }
    return result;
}

// dp 테이블 얻는 함수
vector<vector<pi>> getDpTable(int &n, int &m, vector<int> &num) {
    vector<vector<pi>> dp(n + 1, vector<pi>(m + 1, {0, 0}));

    // 1개 그룹으로 나누는 경우 미리 저장 (누적합)
    for (int i = 1; i <= n; i++) {
        dp[i][1].first = dp[i - 1][1].first + num[i];
    }

    // 그룹 2개부터 구하기
    for (int j = 2; j <= m; j++) {
        for (int i = j; i <= n; i++) {
            int min_max = MAX; // 최대의 최소
            int idx = 0; // 나뉘는 분기 인덱스
            for (int k = j - 1; k < i; k++) {
                int curr_max = max(dp[k][j - 1].first, dp[i][1].first - dp[k][1].first);
                if (curr_max < min_max) {
                    min_max = curr_max;
                    idx = k;
                }
            }
            dp[i][j].first = min_max;
            dp[i][j].second = idx;
        }
    }

    return dp;
}

int main() {
    int n, m;

    cin >> n >> m;
    vector<int> num(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }

    // 최대의 최소 저장
    vector<vector<pi>> dp = getDpTable(n, m, num);

    // 구슬 그룹 개수 구하기
    vector<int> path = getPath(n, m, dp);

    // 출력
    cout << dp[n][m].first << '\n';
    for (int p: path) {
        cout << p << ' ';
    }
    return 0;
}