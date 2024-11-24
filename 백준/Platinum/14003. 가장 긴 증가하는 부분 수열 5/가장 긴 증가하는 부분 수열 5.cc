#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int, int> pi;
const int INF = 1e6;

/**
 * lis의 각 인덱스 별로 가능한 원소와 인덱스 저장한 2차원 배열을 통해 가능한 lis 수열 구해서 리턴하는 함수
 */
vector<int> getLisList(int &lis_len, vector<vector<pi>> &path) {
    vector<int> lis(lis_len, 0);
    int curr_idx = INF;
    for (int i = lis_len - 1; i >= 0; i--) {
        for (int j = path[i].size() - 1; j >= 0; j--) {
            if (path[i][j].second < curr_idx) {
                lis[i] = path[i][j].first;
                curr_idx = path[i][j].second;
                break;
            }
        }
    }
    return lis;
}

/**
 * lis의 결과(lis 수열과 각 인덱스 별 가능한 원소를 저장한 2차원 배열 리턴)
 */
vector<vector<pi>> lisWithBS(int &n, vector<int> &num) {
    vector<int> dp; // lis 수열 중간과정 저장
    vector<vector<pi>> path; // lis 수열과 각 인덱스 별 가능한 원소 저장, first: 값, second: 인덱스
    for (int i = 0; i < n; i++) {
        int idx = lower_bound(dp.begin(), dp.end(), num[i]) - dp.begin();
        if (idx == dp.size()) {
            // 현재 수열에 있는 수보다 크다면
            dp.push_back(num[i]);
            vector<pi> temp = {{num[i], i}};
            path.push_back(temp);
        } else {
            dp[idx] = num[i];
            path[idx].push_back({num[i], i});
        }
    }
    return path;
}

/**
 * DP + 이분탐색 활용해 NlogN 만에 LIS 구하는 문제
 */
int main() {
    int n;

    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    vector<vector<pi>> path = lisWithBS(n, num);
    int lis_len = path.size();
    vector<int> lis = getLisList(lis_len, path);

    cout << lis_len << '\n';
    for (int i = 0; i < lis_len; i++) {
        cout << lis[i] << ' ';
    }
    return 0;
}
