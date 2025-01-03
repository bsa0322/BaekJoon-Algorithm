#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
const ll SIZE = 1e6;

int main() {
    vector<ll> ans(SIZE + 1, 0);
    for (ll i = 1; i <= SIZE; i++) {
        ans[i] = ans[i - 1] + (i * i);
    }
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << ans[n] << '\n';
    }
    return 0;
}