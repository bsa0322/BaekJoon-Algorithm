//
// Created by BaeSuA on 2022-09-04.
//

#include <iostream>

using namespace std;
const long long SIZE = 9223372036854775807;

int main() {
    long long n, sx, sy, ex, ey, c, x, y, ans = SIZE, oem = 0;

    cin >> n >> sx >> sy >> ex >> ey;
    for (long long i = 1; i <= n; i++) {
        cin >> c;
        long long cx = sx, cy = sy, dist = 0;
        while (c--) {
            cin >> x >> y;
            dist += abs(cx - x) + abs(cy - y);
            cx = x;
            cy = y;
        }
        dist += abs(ex - cx) + abs(ey - cy);
        //cout << dist << ' ';
        if (ans > dist) {
            ans = dist;
            oem = i;
        }
    }
    cout << oem;
    return 0;
}