#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pi;
const int MIN = 2;
const int MAX = 12;

/**
 * 가능한 모든 조합 미리 구해놓기
 */
vector<vector<pi>> getPairSum() {
    vector<vector<pi>> comb(MAX + 1, vector<pi>(0));
    for (int i = MIN; i <= MAX; i++) {
        for (int j = 1; j < i; j++) {
            int other = i - j;
            if (j > 6 || other > 6 || j > other) {
                continue;
            }
            comb[i].emplace_back(j, other);
        }
    }
    return comb;
}

int main() {
    vector<vector<pi>> comb = getPairSum();
    int t, n;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> n;
        cout << "Case " << i << ":\n";
        if (n < MIN || n > MAX) {
            continue;
        }
        for (auto c: comb[n]) {
            cout << '(' << c.first << ',' << c.second << ")\n";
        }
    }
    return 0;
}