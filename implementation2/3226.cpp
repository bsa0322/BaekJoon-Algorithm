//
// Created by BaeSuA on 2022-09-13.
//

#include <iostream>

using namespace std;

int calc(int h, int m, int d) {
    int ans = 0;
    while (d--) {
        if (h >= 7 && h < 19) {
            ans += 10;
        } else {
            ans += 5;
        }
        m++;
        h += (m / 60) % 24;
        m %= 60;

    }
    return ans;
}

/**
 * 7:00-19:00 -> 1분에 10원
 * 19:00-7:00 -> 1분에 5원
 */

int main() {
    string clock;
    int n, d;
    int ans = 0;

    // 입력
    cin >> n;
    while (n--) {
        cin >> clock >> d;
        int mid = clock.find(':');
        int h = stoi(clock.substr(0, mid));
        int m = stoi(clock.substr(mid + 1));

        ans += calc(h, m, d);
    }

    cout << ans;
    return 0;
}