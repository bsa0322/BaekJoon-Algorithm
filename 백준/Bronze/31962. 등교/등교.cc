#include <iostream>

using namespace std;

int main() {
    int n, x, s, t;
    int ans = -1;
    cin >> n >> x;
    while (n--) {
        cin >> s >> t;
        if ((s + t) <= x) {
            ans = max(ans, s);
        }
    }
    cout << ans;
    return 0;
}