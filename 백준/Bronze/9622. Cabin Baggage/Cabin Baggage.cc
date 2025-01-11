#include <iostream>

using namespace std;
const double H = 56;
const double R = 45;
const double C = 25;
const double TOTAL = 125;
const double W = 7;

int main() {
    int t, ans = 0;
    double h, r, c, w;
    cin >> t;
    while (t--) {
        cin >> h >> r >> c >> w;
        if (((h <= H && r <= R && c <= C) || (h + r + c) <= TOTAL) && w <= W) {
            ans++;
            cout << 1;
        } else {
            cout << 0;
        }
        cout << '\n';
    }
    cout << ans;
    return 0;
}