#include <iostream>
#include <unordered_map>
#include <cmath>

using namespace std;
const int INF = 100;

unordered_map<int, int> dp; // 숫자 개수 저장

int getDigits(int n) {
    if (dp[n] != 0) {
        return dp[n];
    }
    if (n < 10) {
        return dp[n] = 1;
    }
    int ans = INF; // 자릿수
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i != 0) {
            continue;
        }
        int other = n / i;
        int d1 = getDigits(i);
        int d2 = getDigits(other);
        if (d1 == -1 || d2 == -1) {
            continue;
        }
        ans = min(ans, (d1 + d2));
    }
    if (ans == INF) {
        return dp[n] = -1;
    }
    return dp[n] = ans;
}

int main() {
    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        cout << getDigits(n) << '\n';
    }
    return 0;
}