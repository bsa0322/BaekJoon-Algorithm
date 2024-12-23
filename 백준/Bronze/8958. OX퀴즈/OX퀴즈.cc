#include <iostream>

using namespace std;

int main() {
    int t;
    string str;
    cin >> t;
    while (t--) {
        cin >> str;

        int ans = 0;
        int cnt = 0;
        for (auto c: str) {
            if (c == 'O') {
                cnt++;
                ans += cnt;
            } else {
                cnt = 0;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}