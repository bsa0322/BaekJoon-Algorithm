#include <iostream>
#include <map>

using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

ll getAllCaseCnt(string &str) {
    map<char, ll> mp; // 알파벳 개수
    for (char &c: str) {
        mp[c]++;
    }
    if (mp.size() < 4) {
        // 염기 종류 4개 만족 못하면
        return 0;
    }

    ll ans = 1;
    for (auto &c: mp) {
        ans *= c.second;
        ans %= MOD;
    }
    return ans;
}

int main() {
    int n;
    string str;
    cin >> n;
    cin >> str;

    cout << getAllCaseCnt(str);
    return 0;
}