#include <iostream>

using namespace std;

int main() {
    int n, f;
    cin >> n >> f;
    int ans = 100;
    for (int i = 0; i < 100; i++) {
        int new_n = int(n / 100) * 100 + i;
        if (new_n % f == 0) {
            ans = min(ans, i);
        }
    }
    if (ans < 10) {
        cout << '0' << ans;
    } else {
        cout << ans;
    }
    return 0;
}