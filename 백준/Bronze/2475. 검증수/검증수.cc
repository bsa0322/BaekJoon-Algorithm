#include <iostream>

using namespace std;
typedef long long ll;

int main() {
    ll n, ans = 0;
    for (int i = 0; i < 5; i++) {
        cin >> n;
        ans += (n * n) % 10;
    }
    ans %= 10;
    cout << ans;
    return 0;
}