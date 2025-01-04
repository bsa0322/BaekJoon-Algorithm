#include <iostream>

using namespace std;

int main() {
    int t, l;
    string ans, student;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> l >> ans >> student;
        int cnt = 0;
        for (int i = 0; i < l; i++) {
            if (ans[i] != student[i]) {
                cnt++;
            }
        }
        cout << "Case " << i << ": " << cnt << '\n';
    }
    return 0;
}