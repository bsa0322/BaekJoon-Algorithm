#include <iostream>
#include <set>

using namespace std;
const int INF = 2e9;
const int LIMIT = 60 * 6;

int getMinute(int &h, int &m) {
    if (h == -1 && m == -1) {
        return INF;
    }
    return 60 * h + m;
}

int main() {
    int t, k, n, x, h, m;
    cin >> t;

    while (t--) {
        cin >> k;
        int cnt = 0, best_t = INF, best = 0;
        set<int> student;
        while (k--) {
            cin >> x;
            student.insert(x);
        }
        cin >> n;
        while (n--) {
            cin >> x >> h >> m;
            if (student.find(x) != student.end()) {
                // 수강생이라면
                int total_t = getMinute(h, m);
                if (total_t > LIMIT) {
                    continue;
                }
                cnt++;
                if (best_t > total_t) {
                    best_t = total_t;
                    best = x;
                }
            }
        }
        cout << best << ' ' << cnt << '\n';
    }
    return 0;
}