#include <iostream>

using namespace std;

int main() {
    int t, x1, y1, f1, x2, y2, f2;
    cin >> t;
    while (t--) {
        cin >> x1 >> y1 >> f1 >> x2 >> y2 >> f2;
        int d = abs(x1 - x2) + abs(y1 - y2) + f1 + f2;
        cout << d << '\n';
    }
    return 0;
}