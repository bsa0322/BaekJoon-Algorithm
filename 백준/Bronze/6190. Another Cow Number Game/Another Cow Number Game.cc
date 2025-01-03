#include <iostream>

using namespace std;
typedef long long ll;

int main() {
    ll n, ans = 0;
    cin >> n;
    while (n != 1) {
        if (n % 2 == 1) {
            n = n * 3 + 1;
        } else {
            n /= 2;
        }
        ans++;
    }
    cout << ans;
    return 0;
}