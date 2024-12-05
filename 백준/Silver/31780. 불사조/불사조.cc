#include <iostream>

using namespace std;
typedef long long ll;

ll getSumPower(int x, int cnt) {
    if (cnt == 0) {
        return x;
    }
    ll a = getSumPower(x / 2, cnt - 1);
    ll b = getSumPower(x - x / 2, cnt - 1);
    return x + a + b;
}

int main() {
    int x, m;

    cin >> x >> m;

    cout << getSumPower(x, m);
    return 0;
}