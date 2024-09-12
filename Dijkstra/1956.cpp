#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pi;

const int INF = 1e9;

// 사이클을 이루는 도로의 길이의 합이 최소
// 사이클 -> 유니온 파인드로 찾을 수 있음 ... 유니온 파인드 하면서 최소 ..?
// 단방향.. 유니온 파인드 못 쓸듯!!
// 다익스트라 쓰고 사이클 여부 판단하면 되려나..?

int dijkstra(int start, int &v, vector<vector<pi>> &graph, vector<vector<int>> &connect) {
    vector<int> dist(v + 1, INF);
    priority_queue<pi, vector<pi>, greater<>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int node = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        // 이거 없으면 시간초과 !!
        if (dist[node] < d) {
            continue;
        }

        for (auto &next_node: graph[node]) {
            if (d + next_node.second < dist[next_node.first]) {
                dist[next_node.first] = d + next_node.second;
                pq.push({d + next_node.second, next_node.first});
            }
        }
    }

    int ans = INF;
    for (int i = 1; i <= v; i++) {
        if (i != start && connect[i][start]) {
            ans = min(ans, dist[i] + connect[i][start]);
        }
    }

    return ans;

}

int main() {
    int v, e, a, b, c;

    cin >> v >> e;
    vector<vector<pi>> graph(v + 1, vector<pi>(0));
    vector<vector<int>> connect(v + 1, vector<int>(v + 1, 0));
    while (e--) {
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
        connect[a][b] = c;
    }

    int ans = INF;
    for (int i = 1; i <= v; i++) {
        ans = min(ans, dijkstra(i, v, graph, connect));
    }

    cout << (ans == INF ? -1 : ans);

    return 0;
}