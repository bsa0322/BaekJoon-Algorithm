#include <iostream>

using namespace std;
typedef long long ll;

int main() {
    ll x, y, w, s, ans = 0;

    cin >> x >> y >> w >> s;

    ll min_val = min(x, y);
    ll max_val = max(x, y);
    ll dist = max_val - min_val;

    if (w >= s) { // 다이렉트 대각선으로 가는 게 빠르다면
        if (dist % 2 == 0) {
            ans = max_val * s;
        } else {
            ans = (max_val - 1) * s + w;
        }
    } else if (2 * w >= s) { // 대각선으로 가는 게 더 빠르다면
        ans = min_val * s + dist * w;
    } else {
        ans = w * (x + y);
    }

    cout << ans;
    return 0;
}