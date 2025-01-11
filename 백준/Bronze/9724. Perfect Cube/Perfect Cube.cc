#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t, a, b;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> a >> b;
        int a_cbrt = cbrt(a);
        int b_cbrt = cbrt(b);
        if (pow(a_cbrt, 3) != a) {
            a_cbrt++;
        }
        cout << "Case #" << i << ": " << b_cbrt - a_cbrt + 1 << '\n';
    }
    return 0;
}