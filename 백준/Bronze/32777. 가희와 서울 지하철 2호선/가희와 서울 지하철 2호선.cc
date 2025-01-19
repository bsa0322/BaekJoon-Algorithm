#include <iostream>

using namespace std;

int main() {
    int q, a, b;
    cin >> q;
    while (q--) {
        cin >> a >> b;
        int inner = (b - a);
        if (inner < 0) {
            inner += 43;
        }
        int outer = (a - b);
        if (outer < 0) {
            outer += 43;
        }
        if (inner == outer) {
            cout << "Same";
        } else if (inner < outer) {
            cout << "Inner circle line";
        } else {
            cout << "Outer circle line";
        }
        cout << '\n';
    }
    return 0;
}