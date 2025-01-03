#include <iostream>

using namespace std;
const int INF = 2e9;

int main() {
    int x, y, n, tx, ty, ans_x, ans_y, ans_d = INF;
    cin >> x >> y >> n;
    while (n--) {
        cin >> tx >> ty;
        int d = abs(x - tx) + abs(y - ty);
        if (ans_d > d) {
            ans_d = d;
            ans_x = tx;
            ans_y = ty;
        }
    }
    cout << ans_x << ' ' << ans_y;
    return 0;
}