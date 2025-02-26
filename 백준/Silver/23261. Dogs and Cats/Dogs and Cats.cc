#include <iostream>

using namespace std;
typedef long long ll;

bool isPossible(int &n, int &d, ll &c, int &m, string &animals) {
    int i;
    for (i = 0; i < n; i++) {
        if (animals[i] == 'C') {
            if (c) {
                c--;
            } else {
                break;
            }
        } else {
            if (d) {
                d--;
                c += m;
            } else {
                return false;
            }
        }
    }
    // 개 남았는지 확인
    for (int j = i; j < n; j++) {
        if (animals[j] == 'D') {
            return false;
        }
    }
    return true;
}

int main() {
    int t, n, d, m;
    ll c;
    string animals;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> n >> d >> c >> m >> animals;
        cout << "Case #" << i << ": " << (isPossible(n, d, c, m, animals) ? "YES" : "NO") << '\n';
    }
    return 0;
}