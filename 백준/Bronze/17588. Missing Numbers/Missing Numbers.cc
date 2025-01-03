#include <iostream>
#include <vector>

using namespace std;
const int MAX = 200;

int main() {
    int n, x, last_num = 0;
    vector<bool> check(MAX + 1, false);
    cin >> n;
    while (n--) {
        cin >> x;
        check[x] = true;
        last_num = max(last_num, x);
    }
    bool ans = true;
    for (int i = 1; i <= last_num; i++) {
        if (!check[i]) {
            ans = false;
            cout << i << '\n';
        }
    }
    if (ans) {
        cout << "good job";
    }

    return 0;
}