//
// Created by cse_asus on 2022-10-06.
//

/**
 * 어두운 굴다리
 *
 * 최소한의 높이로 모든 길이 비추기
 * -> 길이를 이분탐색하며 모든 길이 비추는지 확인하기. 이 중 최솟값 찾기 = lowerBound
 */

#include <iostream>
#include <vector>

using namespace std;

bool isPossible(int n, int height, vector<int> &lamp) {
    vector<bool> visited(n + 1, false);
    int cur = 0;
    for (int i = 0; i < lamp.size(); i++) {
        if (cur < lamp[i] - height) { //지난 구간의 마지막을 이어서 커버하지 못하면 바로 false
            return false;
        }
        cur = lamp[i] + height;
    }
    if (cur < n) {
        return false;
    }
    return true;
}

int lowerSearch(int left, int right, int n, vector<int> &lamp) {
    while (left <= right) {
        int mid = (left + right) / 2;
        bool possible = isPossible(n, mid, lamp);

        if (!possible) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return right + 1;
}

int main() {
    int n, m;

    cin >> n >> m;
    vector<int> lamp(m, 0);
    for (int i = 0; i < m; i++) {
        cin >> lamp[i];
    }

    cout << lowerSearch(1, n, n, lamp);
    return 0;
}