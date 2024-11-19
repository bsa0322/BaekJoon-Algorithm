#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pi;

int prim(int &m, int start, vector<vector<pi>> &graph) {
    vector<bool> visited(m, false);
    priority_queue<pi, vector<pi>, greater<>> pq; // first: 간선 가중치, second: 정점

    int cost = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        int curr_weight = pq.top().first;
        int curr_node = pq.top().second;
        pq.pop();

        if (visited[curr_node]) {
            // 이미 방문한 노드라면
            continue;
        }
        // 방문 체크
        visited[curr_node] = true;
        cost += curr_weight;

        // 현재 정점에서 간선 작은 정점 누적
        for (int i = 0; i < graph[curr_node].size(); i++) {
            int next_node = graph[curr_node][i].first;
            int next_weight = graph[curr_node][i].second;
            if (!visited[next_node]) {
                // 방문하지 않은 노드라면
                pq.push({next_weight, next_node});
            }
        }
    }
    return cost;
}

/**
 * 완전 기본 MST
 * 절약할 수 있는 최대 액수 -> (전체 금액 - 전력의 최소 금액)
 *
 * Prim: 시작 정점에서 시작해서, 간선의 가중치가 작은 정점을 N-1개 고르는 방식
 */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, n, x, y, z;

    while (cin >> m >> n) {
        if (m == 0 && n == 0) {
            break;
        }
        int total = 0;
        vector<vector<pi>> graph(m, vector<pi>());
        while (n--) {
            cin >> x >> y >> z;
            graph[x].emplace_back(y, z);
            graph[y].emplace_back(x, z);
            total += z;
        }

        // 전체 금액 - 전력 최소 금액
        int min_cost = prim(m, 0, graph);
        cout << total - min_cost << '\n';
    }
    return 0;
}