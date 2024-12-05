#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int> pi;

int getMinimumTime(int &n, int &s, int &e, vector<vector<int>> &teleport) {
    queue<pi> q;
    vector<bool> check(n + 1, false);
    q.push({s, 0});

    while (!q.empty()) {
        int curr_n = q.front().first;
        int curr_t = q.front().second;
        q.pop();

        if (curr_n == e) {
            return curr_t;
        }
        vector<int> next_n;
        for (auto t: teleport[curr_n]) {
            next_n.push_back(t);
        }
        next_n.push_back(curr_n - 1);
        next_n.push_back(curr_n + 1);
        for (auto node: next_n) {
            if (node < 1 || node > n || check[node]) {
                continue;
            }
            check[node] = true;
            q.push({node, curr_t + 1});
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, s, e, x, y;

    cin >> n >> m >> s >> e;
    vector<vector<int>> teleport(n + 1, vector<int>());
    while (m--) {
        cin >> x >> y;
        teleport[x].push_back(y);
        teleport[y].push_back(x);
    }

    cout << getMinimumTime(n, s, e, teleport);
    return 0;
}