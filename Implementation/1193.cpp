#include <iostream>

using namespace std;

int main() {
    bool flag = false;
    int n, cnt = 0, a = 1, b = 1;

    cin >> n;
    for (int i = 1;; i++) {
        for (int j = 1; j <= i; j++) {
            if (i % 2 == 1) {
                // 분모가 j, 분자가 i - j + 1
                a = i - j + 1;
                b = j;
            } else {
                // 분모가 i - j + 1, 분자가 j
                a = j;
                b = i - j + 1;
            }
            cnt++;
            if (cnt == n) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

    cout << a << '/' << b;

    return 0;
}