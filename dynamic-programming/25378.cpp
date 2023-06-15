#include <iostream>
#include <vector>

using namespace std;

vector<vector<bool>> checkPoss(int &n, vector<int> &rocks){
    vector<vector<bool>> check(n + 1, vector<bool>(n + 1, false));
    for (int i = 1; i <= n; i++) {
        bool poss = true;
        int prev = rocks[i];
        for (int j = i + 1; j <= n; j++) {
            if (prev == rocks[j]) {
                check[i][j] = poss;
            } else if (prev > rocks[j]) {
                poss = false;
            }
            prev = abs(rocks[j] - prev);
        }
    }
    return check;
}

int minCnt(int &n, vector<vector<bool>> &check){
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        for (int j = 1; j < i; j++) {
            if (!check[j][i]) {
                continue;
            }
            dp[i] = min(dp[i], dp[j - 1] + i - j);
        }
    }
    return dp[n];
}

// 우선 l ~ r 까지 1번으로 주서갈 수 있는지 확인 -> 만약 된다면 r - l 번만에 가져가기 가능
int main() {
    int n;
    cin >> n;
    vector<int> rocks(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> rocks[i];
    }

    vector<vector<bool>> check = checkPoss(n, rocks);
    cout << minCnt(n,check);
    return 0;
}