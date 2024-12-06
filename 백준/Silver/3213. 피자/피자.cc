#include <iostream>
#include <vector>
#include <map>

using namespace std;
const string ONE_FOURTH = "1/4";
const string ONE_HALF = "1/2";
const string THREE_FOURTH = "3/4";

int getMinimumPizza(int &n, map<string, int> &mp) {
    // 1/2 먼저 먹기
    int ans = (mp[ONE_HALF] / 2);
    int extra_one_half = mp[ONE_HALF] % 2;
    ans += extra_one_half;

    // 1/4 + 3/4 먹기
    ans += min(mp[ONE_FOURTH], mp[THREE_FOURTH]);

    if (mp[ONE_FOURTH] > mp[THREE_FOURTH]) {
        // 1/4가 더 많이 남았다면
        mp[ONE_FOURTH] -= mp[THREE_FOURTH];
        mp[ONE_FOURTH] -= (extra_one_half * 2);
        if (mp[ONE_FOURTH] > 0) {
            ans += ((mp[ONE_FOURTH] + 3) / 4);
        }
    } else if (mp[ONE_FOURTH] < mp[THREE_FOURTH]) {
        // 3/4 가 더 많이 남았다면
        ans += (mp[THREE_FOURTH] - mp[ONE_FOURTH]);
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    string str;
    map<string, int> mp;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str;
        mp[str]++;
    }

    cout << getMinimumPizza(n, mp);
    return 0;
}