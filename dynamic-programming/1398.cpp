#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
const ll MAX = 1e15 + 1;

/**
 * https://www.acmicpc.net/problem/1398
 * 냅색 + 그리디
 * 동전이 10의 배수, 25의 100배수로 있으니 1, 10, 25, 100, ... 반복됨
 * 따라서 1 ~ 100 까지 냅색으로 정답 구해놓은 후, 입력받은 수 100 단위로 dp 값 더해주기
 * */

int main() {
    ll chocolate;
    int t;
    cin >> t;

    vector<ll> dp(101, MAX);
    vector<int> coin = {1, 10, 25, 100};
    dp[0] = 0;
    for (int i = 0; i < coin.size(); i++) {
        for (int j = coin[i]; j <= 100; j++) {
            dp[j] = min(dp[j], dp[j - coin[i]] + 1);
        }
    }

    while (t--) {
        cin >> chocolate;

        ll ans = 0;
        while (chocolate) {
            ll num1 = chocolate % 100;
            chocolate /= 100;
            ans += dp[num1];
        }
        cout << ans << '\n';
    }
    return 0;
}