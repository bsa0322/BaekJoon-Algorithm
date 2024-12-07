#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lis(int &n, vector<int> &port) {
    vector<int> dp;
    for (int i = 0; i < n; i++) {
        int idx = lower_bound(dp.begin(), dp.end(), port[i]) - dp.begin();
        if (idx == dp.size()) {
            // 현재 값이 가장 크다면
            dp.push_back(port[i]);
        } else {
            dp[idx] = port[i];
        }
    }

    return dp.size();
}

/**
 * O(NlogN) 걸리는 LIS 알고리즘으로 LIS 구하는 문제
 */
int main() {
    int n;

    cin >> n;
    vector<int> port(n);
    for (int i = 0; i < n; i++) {
        cin >> port[i];
    }

    cout << lis(n, port);
    return 0;
}