#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double d, rh, rv;
    while (cin >> d >> rh >> rv) {
        if (d == 0 && rh == 0 && rv == 0) {
            break;
        }
        double w = (16 * d) / sqrt(337);
        double h = (9 * w / 16);

        cout << fixed;
        cout.precision(2);
        cout << "Horizontal DPI: " << (rh / w) << '\n';
        cout << "Vertical DPI: " << (rv / h) << '\n';
    }
    return 0;
}