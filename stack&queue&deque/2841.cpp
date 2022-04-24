#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> st[7]; //1 ~ 6줄 기타
    int n, p, a, b, ans = 0;
    cin >> n >> p;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (st[a].empty()) {
            st[a].push(b);
            ans++;
            continue;
        }
        while (!st[a].empty() && st[a].top() > b) {
            st[a].pop();
            ans++;
        }
        if (!st[a].empty() && st[a].top() == b) continue;
        st[a].push(b);
        ans++;
    }
    cout << ans << '\n';
    return 0;
}