#include <iostream>

using namespace std;

int main() {
    int n, x, ans = 1;
    cin >> n >> x;
    bool is_odd = (x % 2 == 1);
    for (int i = 1; i < n; i++) {
        cin >> x;
        if (is_odd && x % 2 == 0) {
            ans++;
            is_odd = false;
        } else if (!is_odd && x % 2 == 1) {
            ans++;
            is_odd = true;
        }
    }
    cout << ans;
    return 0;
}