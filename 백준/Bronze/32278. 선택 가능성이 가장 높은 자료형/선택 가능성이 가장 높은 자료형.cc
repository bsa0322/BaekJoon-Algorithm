#include <iostream>

using namespace std;
typedef long long ll;
const ll SHORT = -32768;
const ll INT = -2147483648;

int main() {
    ll n;
    cin >> n;
    if (n >= SHORT && n < -SHORT) {
        cout << "short";
    } else if (n >= INT && n < -INT) {
        cout << "int";
    } else {
        cout << "long long";
    }
    return 0;
}