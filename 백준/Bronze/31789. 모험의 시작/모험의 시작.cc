#include <iostream>

using namespace std;

int main() {
    int n, x, s, c, p;
    cin >> n >> x >> s;

    bool ans = false;
    while (n--) {
        cin >> c >> p;
        if (c <= x && p > s) {
            ans = true;
        }
    }
    cout << (ans ? "YES" : "NO");
    return 0;
}