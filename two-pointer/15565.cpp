#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e6 + 1;

/**
 * 라이언 1, 어피치 2
 */

int main() {
    int n, k;

    cin >> n >> k;
    vector<int> dolls(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> dolls[i];
    }

    int l = 0, r = 0, ans = INF;
    int cnt = (dolls[0] == 1 ? 1 : 0);
    while (l <= r && r < n) {
        if (cnt == k) {
            ans = min(ans, r - l + 1);
        }
        if (cnt < k) {
            r++;
            if (r < n && dolls[r] == 1) {
                cnt++;
            }
        } else {
            if (dolls[l] == 1) {
                cnt--;
            }
            l++;
        }
    }

    cout << (ans == INF ? -1 : ans);

    return 0;
}