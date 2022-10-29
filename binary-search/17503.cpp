//
// Created by BaeSuA on 2022-10-29.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;

bool check(long long bias, int n, int m, vector<ci> &beer) {
    int like = 0;
    vector<int> result;
    for (int i = 0; i < beer.size(); i++) {
        if (bias < beer[i].first) {
            break;
        }
        result.push_back(beer[i].second);
    }
    if (result.size() < n) {
        return false;
    }
    sort(result.begin(), result.end(), greater<>());
    for (int i = 0; i < n; i++) {
        like += result[i];
    }
    return like >= m;
}

int solution(long long left, long long right, int n, int m, vector<ci> &beer) {
    int ans = -1;
    while (left <= right) {
        long long mid = (left + right) / 2;
        bool chk = check(mid, n, m, beer);
        if (chk) {
            right = mid - 1;
            ans = mid;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

/**
 * 간 레벨들이 선호도 합 M개 이상을 만족하는지 확인하고, 이중 최솟값을 구하자!
 *
 * 자료형 범위가 까다로웠던 문제.. 문제에 주어지는 값들 자체는 int범위 이내이지만 이분탐색하는 과정에서 left, right, mid값이 int 범위 넘는 경우 생길 수 있으므로
 * long long을 써줘야 했음! 안그러면 오버플로우때문에 시간초과
 */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k, right = 0;

    cin >> n >> m >> k;

    vector<ci> beer(k, {0, 0});

    for (int i = 0; i < k; i++) {
        cin >> beer[i].second >> beer[i].first;
        right = max(right, beer[i].first);
    }

    sort(beer.begin(), beer.end());
    cout << solution(0, right, n, m, beer);
    return 0;
}