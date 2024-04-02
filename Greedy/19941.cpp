#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string hamburger;
    cin >> hamburger;
    int ans = 0;
    for (int i = 0; i < hamburger.length(); i++) {
        if (hamburger[i] == 'H' || hamburger[i] == 'C') {
            continue;
        }
//        cout << "현재 : " << i << '\n';
        bool flag = true;
        for (int j = i - k; j < i; j++) {
            if (j < 0) {
                continue;
            }
            if (hamburger[j] == 'H') {
                flag = false;
                hamburger[j] = 'C';
                ans++;
//                cout << "h " << j << '\n';
                break;
            }
        }
        if (flag) {
            for (int j = i + 1; j <= i + k; j++) {
                if (j >= n) {
                    break;
                }
                if (hamburger[j] == 'H') {
                    hamburger[j] = 'C';
                    ans++;
//                    cout << "h " << j << '\n';
                    break;
                }
            }
        }
//        for (int j = 0; j < n; j++) {
//            printf("%4d", j);
//        }
//        cout << '\n';
//        for (int j = 0; j < n; j++) {
//            printf("%4c", hamburger[j]);
//        }
//        cout << '\n';
    }
    cout << ans;
    return 0;
}