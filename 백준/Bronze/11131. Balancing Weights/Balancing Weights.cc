#include <iostream>

using namespace std;

int main() {
    int t, n, w;
    cin >> t;
    while (t--) {
        cin >> n;
        int left = 0, right = 0;
        while (n--) {
            cin >> w;
            if (w < 0) {
                left += abs(w);
            } else {
                right += w;
            }
        }
        if (left < right) {
            cout << "Right";
        } else if (left > right) {
            cout << "Left";
        } else {
            cout << "Equilibrium";
        }
        cout << '\n';
    }
    return 0;
}