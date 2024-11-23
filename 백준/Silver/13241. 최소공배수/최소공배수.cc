#include <iostream>

using namespace std;
typedef long long ll;

ll getGcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return getGcd(b, a % b);
}

int main() {
    ll a, b;
    cin >> a >> b;

    ll gcd = getGcd(max(a, b), min(a, b));
    ll lcm = a * b / gcd;

    cout << lcm;
    return 0;
}