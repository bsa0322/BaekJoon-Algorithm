#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, a, b;

    cin >> t;
    while (t--) {
        cin >> a >> b;
        if (a > b) {
            cout << gcd(a, b) << '\n';
        } else {
            cout << gcd(b, a) << '\n';
        }
    }
    return 0;
}