#include <iostream>

using namespace std;
const int MAX = 1e4 + 99;

int main() {
    int n, min = 1e4, ans = 99;

    cin >> n;
    for (int i = 99; i <= MAX; i++) {
        string n_str = to_string(i);
        int len = n_str.length();
        if (n_str[len - 1] == '9' && n_str[len - 2] == '9') {
            if (min >= abs(i - n)) {
                min = abs(i - n);
                ans = i;
            }
        }
    }
    cout << ans;
    return 0;
}