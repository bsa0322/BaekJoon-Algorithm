#include <iostream>
#include <cmath>

using namespace std;
typedef long long int ll;

ll GCD(ll a, ll b) {
    if (b != 0) return GCD(b, a % b);
    return a;
}

int main() {
    ll a, b, idx = 1, ta = 0, tb = 0, ans_a = 0, ans_b = 0;
    cin >> a >> b;

    if (a == b) {
        ans_a = a;
        ans_b = b;
    } else {
        ll multi = a * b;
        while (true) {
            ta = a * idx;
            tb = b / idx;
            idx++;

            if (ta > tb) break;
            if (tb % a != 0) continue;

            //최대공약수와 최소공배수 원래 값과 같은지 비교
            if (GCD(max(ta,tb), min(ta,tb)) == a && ta * tb == multi) {
                ans_a = ta;
                ans_b = tb;
            }
        }
    }

    cout << ans_a << ' ' << ans_b << '\n';

    return 0;
}