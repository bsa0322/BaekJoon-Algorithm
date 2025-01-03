#include <iostream>

using namespace std;

int main() {
    int n, x;
    int cnt[2] = {0};
    cin >> n;
    while (n--) {
        cin >> x;
        cnt[x]++;
    }
    cout << min(cnt[0], cnt[1]);
    return 0;
}