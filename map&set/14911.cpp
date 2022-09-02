//
// Created by BaeSuA on 2022-09-01.
//

#include <iostream>
#include <map>

using namespace std;

/**
 * 정수들을 맵에 저장해서 숫자 개수 카운트
 */

int main() {
    int num, sum;
    map<int, int> mp;

    while (cin >> num) {
        sum = num;
        mp[num]++;
    }
    mp[sum]--;

    int cnt = 0;
    for (auto x: mp) {
        int y = sum - x.first;
        mp[x.first]--;
        if (y < (sum + 1) / 2) {
            break;
        }
        if (mp[y] > 0) {
            cout << x.first << ' ' << y << '\n';
            cnt++;
            mp[y]--;
        }
    }
    cout << cnt << '\n';
    return 0;
}