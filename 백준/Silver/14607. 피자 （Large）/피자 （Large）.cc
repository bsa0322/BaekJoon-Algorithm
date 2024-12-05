#include <iostream>
#include <map>

using namespace std;
typedef long long ll;
map<ll, ll> mp;

ll getMaxFun(int n) {
    if (n == 1) {
        return 0;
    }
    if (mp[n]) {
        return mp[n];
    }

    ll value = n / 2;
    ll other = n - value;
    return mp[n] = value * other + getMaxFun(value) + getMaxFun(other);
}

int main() {
    ll n;

    cin >> n;

    cout << getMaxFun(n);
    return 0;
}