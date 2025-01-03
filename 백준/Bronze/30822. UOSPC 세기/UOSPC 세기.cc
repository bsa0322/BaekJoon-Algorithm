#include <iostream>
#include <vector>
#include <set>

using namespace std;
const int ALPHA = 26;

int main() {
    int n;
    string input;
    cin >> n >> input;
    vector<int> cnt(ALPHA, 0);
    for (auto c: input) {
        cnt[c - 'a']++;
    }
    set<char> st = {'u', 'o', 's', 'p', 'c'};
    int ans = 1000;
    for (auto idx: st) {
        ans = min(ans, cnt[idx - 'a']);
    }

    cout << ans;
    return 0;
}