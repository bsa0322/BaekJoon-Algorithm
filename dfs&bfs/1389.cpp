#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int INF = 1e9;
typedef pair<int, int> pi;

/**
 * 케빈베이컨 수가 가장 적은 사람 구하기
 *
 */

int bfs(int start, int &n, vector<vector<bool>> &graph) {
    vector<bool> check(n + 1, false);
    vector<int> cnt(n + 1, 0);
    queue<pi> q;

    check[start] = true;
    q.push({start, 0});
    while (!q.empty()) {
        int cur_node = q.front().first;
        int cur_cnt = q.front().second;
        q.pop();

        if (cnt[cur_node] == 0) {
            cnt[cur_node] = cur_cnt;
        }

        for (int i = 1; i <= n; i++) {
            if (graph[cur_node][i] && !check[i]) {
                check[i] = true;
                q.push({i, cur_cnt + 1});
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += cnt[i];
    }
    return ans;
}

int main() {
    int n, m, a, b;

    cin >> n >> m;
    vector<vector<bool>> graph(n + 1, vector<bool>(n + 1, false));

    while (m--) {
        cin >> a >> b;
        graph[a][b] = graph[b][a] = true;
    }

    int ans = INF;
    int person = 0;
    for (int i = 1; i <= n; i++) {
        int temp = bfs(i, n, graph);
        if (ans > temp) {
            ans = temp;
            person = i;
        }
    }
    cout << person;
    return 0;
}