#include<iostream>

using namespace std;

string s, ans;

void divide(int st, int ed) {
    if (st == ed)
        return;
    int idx = 0;
    while (true) {
        if (st + idx >= ed - idx) break;
        if (s[st + idx] == s[ed - idx]) {
            ans = "NO";
            return;
        }
        idx++;

    }
    divide(st, (st + ed) / 2 - 1);
    divide((st + ed) / 2 + 1, ed);
}

int main() {
    int t;

    cin >> t;

    while (t--) {
        ans = "YES";
        cin >> s;

        divide(0, s.length() - 1);

        cout << ans << '\n';

    }

    return 0;
}