#include <iostream>

using namespace std;

int main() {
    int n, h, b, k, ans = 0;
    cin >> n;
    while (n--) {
        cin >> h >> b >> k;
        if (b < h) {
            continue;
        }
        ans += (b - h) * k;
    }
    cout << ans;
    return 0;
}