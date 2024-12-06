#include <iostream>

using namespace std;
typedef long long ll;

/**
 * x + y = b, y = b - x
 * 위의 식을 gcd(x, y) = a 의 y 부분에 대입하면
 * gcd(x, b - x) = a
 *
 * 위 식은 gcd(b, x) = a 와도 같음
 * x가 적어도 a여야 하므로 b는 적어도 2a의 이상이면서 a의 배수여야 함
 */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll q, a, b;
    cin >> q;

    while (q--) {
        cin >> a >> b;
        cout << (b >= 2 * a && b % a == 0) << '\n';
    }

    return 0;
}