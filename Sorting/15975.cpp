#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
typedef pair<long long, int> pi;
const int INF = 1e9 + 1;

int main() {
    int n, x, y;
    map<int, vector<long long>> mp;
    vector<pi> points;

    cin >> n;
    while (n--) {
        cin >> x >> y;
        mp[y].push_back(x);
        points.emplace_back(x, y);
    }

    long long answer = 0;
    for (auto m: mp) {
        sort(m.second.begin(), m.second.end());
        for (int i = 0; i < m.second.size(); i++) {
            long long diff = INF;
            if (i > 0) {
                diff = min(diff, m.second[i] - m.second[i - 1]);
            }
            if (i < m.second.size() - 1) {
                diff = min(diff, m.second[i + 1] - m.second[i]);
            }
            if (diff != INF) {
                answer += diff;
            }
        }
    }

    cout << answer;

    return 0;
}