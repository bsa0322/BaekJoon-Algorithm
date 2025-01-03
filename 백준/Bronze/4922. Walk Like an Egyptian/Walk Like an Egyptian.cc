#include <iostream>
#include <vector>

using namespace std;
const int MAX = 1e3;

int main() {
    vector<int> ans(MAX, 0);
    ans[1] = 1;
    int diff = 2;
    for (int i = 2; i < MAX; i++) {
        ans[i] = ans[i - 1] + diff;
        diff += 2;
    }
    int n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        cout << n << " => " << ans[n] << '\n';
    }
    return 0;
}