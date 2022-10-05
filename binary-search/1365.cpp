//
// Created by cse_asus on 2022-10-06.
//

/**
 * 꼬인 전깃줄
 * 꼬여 있는 전선 하나도 없게 -> lis
 * N 범위가 100,000이니까 기본 lis 로는 안됨!
 *
 * 이분탐색을 활용해서 하자!
 */

#include <iostream>
#include <vector>

using namespace std;

int lis(int n, vector<int> &power_pole) {
    vector<int> leng;
    leng.push_back(0);
    for (int i = 0; i < n; i++) {
        // lower_bound = 찾고자 하는 값 이상이 처음으로 나오는 곳
        int target = lower_bound(leng.begin(), leng.end(), power_pole[i]) - leng.begin();
        if (target == leng.size()) { // 찾고자 하는 값 이상이 없다면 -> 새로운 길이 추가
            leng.push_back(power_pole[i]);
        } else { //둘 중 더 작은 값을 넣어야, 앞으로의 길이 측정 시 유리
            leng[target] = min(leng[target], power_pole[i]);
        }
    }
    return n - leng.size() + 1;
}

int main() {
    int n;

    cin >> n;
    vector<int> power_pole(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> power_pole[i];
    }

    cout << lis(n, power_pole);
    return 0;
}