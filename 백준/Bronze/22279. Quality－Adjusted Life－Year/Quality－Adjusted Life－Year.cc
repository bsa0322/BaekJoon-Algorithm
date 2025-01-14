#include <iostream>

using namespace std;

int main() {
    int n;
    double q, y;
    double ans = 0;
    cin >> n;
    while (n--) {
        cin >> q >> y;
        ans += q * y;
    }
    cout << fixed;
    cout.precision(3);
    cout << ans;
    return 0;
}