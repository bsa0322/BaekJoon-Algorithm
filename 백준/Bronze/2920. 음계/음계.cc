#include <iostream>

using namespace std;

int main() {
    int n, type = 0;
    for (int i = 1; i <= 8; i++) {
        cin >> n;
        if (type == 2) {
            continue;
        }
        if ((i == 1 || type == 0) && i == n) {
            type = 0;
        } else if ((i == 1 || type == 1) && n == (9 - i)) {
            type = 1;
        } else {
            type = 2;
        }
    }
    if (type == 0) {
        cout << "ascending";
    } else if (type == 1) {
        cout << "descending";
    } else {
        cout << "mixed";
    }
    return 0;
}