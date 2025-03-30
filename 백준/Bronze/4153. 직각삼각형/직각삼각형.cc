#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    while (cin >> a >> b >> c) {
        if (a == 0 && b == 0 && c == 0) {
            break;
        }
        int a2 = a * a;
        int b2 = b * b;
        int c2 = c * c;
        if (a2 == b2 + c2 || b2 == a2 + c2 || c2 == a2 + b2) {
            cout << "right\n";
        } else {
            cout << "wrong\n";
        }
    }
    return 0;
}