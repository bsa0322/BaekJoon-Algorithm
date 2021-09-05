#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
    bool front = true;
    string p, s, x_s = "", ans;
    int t, n;
    cin >> t;
    while (t--) {
        front = true;
        ans = x_s = "";
        deque<int> dq;
        cin >> p >> n >> s;
        for (int i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) {
                x_s += s[i];
            } else {
                if (x_s != "") {
                    dq.push_back(stoi(x_s));
                }
                x_s = "";
            }
        }
        for (int i = 0; i < p.length(); i++) {
            if (p[i] == 'R') {
                if (front) front = false;
                else front = true;
            } else {
                if (!dq.empty()) {
                    if (front) {
                        dq.pop_front();
                    } else {
                        dq.pop_back();
                    }
                } else {
                    ans = "error";
                    break;
                }
            }
        }
        if (ans == "") {
            ans += '[';
            if (front) {
                for (int i = 0; i < dq.size(); i++) {
                    ans += to_string(dq[i]);
                    if (i < dq.size() - 1) ans += ',';
                }
            } else {
                for (int i = dq.size() - 1; i >= 0; i--) {
                    ans += to_string(dq[i]);
                    if (i > 0) ans += ',';
                }
            }
            ans += ']';
        }
        cout << ans << '\n';
    }
    return 0;
}