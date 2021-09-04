#include <iostream>
#include <map>

using namespace std;

int main() {
    map<string, int> mp;
    string s, s2[2500];
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        mp[s] = i;
    }
    for (int i = 0; i < n; i++) cin >> s2[i];
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            bool order = (mp[s2[i]] < mp[s2[j]]);
            if (order) ans++;
        }
    }
    cout << ans << '/' << (n * (n - 1) / 2) << '\n';
    return 0;
}