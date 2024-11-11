#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pi;
const int SIZE = 100;
const int INF = 101;

int getMinimumCnt(vector<int> &ladder, vector<int> &snake) {
    // first: 횟수, second: node
    priority_queue<pi, vector<pi>, greater<>> q; // 최소 힙
    vector<int> check_cnt(SIZE + 1, INF);

    q.push({0, 1});
    check_cnt[1] = 0;
    while (!q.empty()) {
        int curr_cnt = q.top().first;
        int node = q.top().second;
        q.pop();

        if (curr_cnt > check_cnt[node]) {
            continue;
        }

        if (node == SIZE) {
            return curr_cnt;
        }
        for (int i = 1; i <= 6; i++) {
            int next_node = node + i;
            if (next_node > 100) {
                continue;
            }
            if (ladder[next_node] > 0) {
                next_node = ladder[next_node];
            } else if (snake[next_node] > 0) {
                next_node = snake[next_node];
            }

            if (check_cnt[next_node] > (curr_cnt + 1)) {
                q.push({curr_cnt + 1, next_node});
                check_cnt[next_node] = curr_cnt + 1;
            }
        }
    }
    return 0;
}

int main() {
    int n, m, x, y;
    cin >> n >> m;
    vector<int> ladder(SIZE + 1, 0);
    vector<int> snake(SIZE + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        ladder[x] = y;
    }
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        snake[x] = y;
    }

    cout << getMinimumCnt(ladder, snake);
    return 0;
}

