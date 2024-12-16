#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pi;

int getMinCntGoDest(int &n, int &s, int &d, int &f, int &b, vector<bool> &polices) {
    queue<pi> q; // {현재 위치, 현재 버튼 누른 횟수}
    vector<bool> check(n + 1, false);
    q.push({s, 0});
    check[s] = true;
    while (!q.empty()) {
        int curr_x = q.front().first;
        int curr_cnt = q.front().second;
        q.pop();

        if (curr_x == d) {
            return curr_cnt;
        }
        vector<int> next_x = {curr_x + f, curr_x - b};
        for (auto nx: next_x) {
            if (nx < 1 || nx > n || polices[nx] || check[nx]) {
                continue;
            }
            check[nx] = true;
            q.push({nx, curr_cnt + 1});
        }
    }
    return -1; // 목적지 도달 못함
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, s, d, f, b, k, p;
    cin >> n >> s >> d >> f >> b >> k;
    vector<bool> polices(n + 1, false);
    while (k--) {
        cin >> p;
        polices[p] = true;
    }

    int ans = getMinCntGoDest(n, s, d, f, b, polices);
    if (ans == -1) {
        cout << "BUG FOUND";
    } else {
        cout << ans;
    }
    return 0;
}