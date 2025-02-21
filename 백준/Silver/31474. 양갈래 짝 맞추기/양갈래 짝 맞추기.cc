#include <iostream>

using namespace std;

int main() {
    long long ans = 1;
    int n;
    cin >> n;
    for (int i = 4; i <= n; i += 2) {
        ans *= (i - 1);
    }
    cout << ans;
    return 0;
}