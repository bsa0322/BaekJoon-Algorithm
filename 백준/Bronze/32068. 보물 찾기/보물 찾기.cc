#include <iostream>

using namespace std;

int main() {
    int t, l, r, s;
    cin >> t;
    while (t--) {
        cin >> l >> r >> s;
        int left_diff = abs(s - l);
        int right_diff = abs(r - s);
        int diff = right_diff;
        bool direc = false; // 오른쪽
        if (left_diff < right_diff) {
            diff = left_diff;
            direc = true; // 왼쪽
        }
        if (left_diff == 0 || right_diff == 0) {
            direc = true;
        }
        cout << diff * 2 + direc << '\n';
    }
    return 0;
}