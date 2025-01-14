#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

int main() {
    ll h, m, a;
    cin >> h >> m;
    for (ll i = 1; i <= m; i++) {
        a = -6 * pow(i, 4) + h * pow(i, 3) + 2 * pow(i, 2) + i;
        if (a <= 0) {
            cout << "The balloon first touches ground at hour: " << i;
            return 0;
        }
    }
    cout << "The balloon does not touch ground in the given time.";
    return 0;
}