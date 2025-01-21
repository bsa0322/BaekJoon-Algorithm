#include <iostream>

using namespace std;

int getCntNumber(int num, int target) {
    int cnt = 0;
    string str = to_string(num);
    for (auto c: str) {
        if (target == (c - '0')) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int a, b, d, ans = 0;

    cin >> a >> b >> d;
    for (int i = a; i <= b; i++) {
        ans += getCntNumber(i, d);
    }
    cout << ans;
    return 0;
}