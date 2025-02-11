#include <iostream>
#include <vector>
#include <map>

using namespace std;
typedef pair<int, int> pi;

int getCnt(int x, int y, int &n, map<pi, bool> &check) {
    int dr[4] = {-2, 2, 0, 0};
    int dc[4] = {0, 0, -2, 2};

    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        int nr = x + dr[i];
        int nc = y + dc[i];
        if (nr < 1 || nr > n || nc < 1 || nc > n) {
            continue;
        }
        if (!check[{nr, nc}]) {
            check[{nr, nc}] = true;
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int n, k, ans = 0;
    map<pi, bool> check;

    cin >> n >> k;
    vector<pi> pos(k);
    for (int i = 0; i < k; i++) {
        cin >> pos[i].first >> pos[i].second;
        check[{pos[i].first, pos[i].second}] = true;
    }
    for (int i = 0; i < k; i++) {
        ans += getCnt(pos[i].first, pos[i].second, n, check);
    }
    cout << ans;
    return 0;
}