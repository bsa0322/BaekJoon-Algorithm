#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pi;
typedef pair<int, vector<bool>> iv;

// 아직 사용 안한 타일 중 제일 큰 타일 합 및 번호 구하는 {합, 타일 리스트}
iv getMaxInNotUse(int cnt, vector<pi> &cost, vector<bool> &check) {
    int curr = 0;
    int idx = 0;
    int len = cost.size();
    int sum = 0;
    vector<bool> new_check = check;
    while (curr < cnt && idx < len) {
        if (check[cost[idx++].second]) {
            continue;
        }
        curr++;
        sum += cost[idx - 1].first;
        new_check[cost[idx - 1].second] = true;
    }
    if (curr != cnt) {
        // 못 고름
        return {-1, {}};
    }
    return {sum, new_check};
}

int getMaximumCost(int &n, int &a, int &b, vector<pi> &a_cost, vector<pi> &b_cost) {
    vector<vector<bool>> a_check(n + 1, vector<bool>(a, false));
    vector<vector<bool>> b_check(n + 1, vector<bool>(b, false));
    vector<int> dp(n + 1, 0); // 현재 너비까지의 최대 예쁨값 저장

    // 너비 1은 2x1(a) 만 가능하므로 미리 초기화
    dp[1] = a_cost[0].first;
    a_check[1][a_cost[0].second] = true;

    // 너비 2부터 dp
    for (int i = 2; i <= n; i++) {
        // 2 x 1 더하기
        iv temp = getMaxInNotUse(1, a_cost, a_check[i - 1]);
        if (temp.first != -1) {
            if (dp[i] < dp[i - 1] + temp.first) {
                dp[i] = dp[i - 1] + temp.first;
                a_check[i] = temp.second;
                b_check[i] = b_check[i - 1];
            }
        }

        // 2 x 2 더하기
        temp = getMaxInNotUse(1, b_cost, b_check[i - 2]);
        if (temp.first != -1) {
            if (dp[i] < dp[i - 2] + temp.first) {
                dp[i] = dp[i - 2] + temp.first;
                a_check[i] = a_check[i - 2];
                b_check[i] = temp.second;
            }
        }

        // 2 x 2 (2 x 1 2개 눕힌 거) 더하기
        temp = getMaxInNotUse(2, a_cost, a_check[i - 2]);
        if (temp.first != -1) {
            if (dp[i] < dp[i - 2] + temp.first) {
                dp[i] = dp[i - 2] + temp.first;
                a_check[i] = temp.second;
                b_check[i] = b_check[i - 2];
            }
        }
    }

    return dp[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, a, b, x;
    vector<pi> a_cost, b_cost; // {예쁨 값, 인덱스)
    cin >> n >> a >> b;
    for (int i = 0; i < a; i++) {
        cin >> x;
        a_cost.emplace_back(x, i);
    }
    for (int i = 0; i < b; i++) {
        cin >> x;
        b_cost.emplace_back(x, i);
    }

    // 타일들 내림차순 정렬
    sort(a_cost.begin(), a_cost.end(), greater<>());
    sort(b_cost.begin(), b_cost.end(), greater<>());

    cout << getMaximumCost(n, a, b, a_cost, b_cost);
    return 0;
}