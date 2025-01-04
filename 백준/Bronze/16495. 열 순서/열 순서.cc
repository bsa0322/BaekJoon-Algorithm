#include <iostream>

using namespace std;
typedef long long ll;
const ll ALPHA = 26;

int main() {
    string input;
    cin >> input;
    ll ans = 0;
    ll multi = 1;
    for (int i = input.length() - 1; i >= 0; i--) {
        int curr = input[i] - 'A' + 1;
        ans += multi * curr;
        multi *= ALPHA;
    }
    cout << ans;
    return 0;
}