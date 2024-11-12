#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> pi;
const int INF = 2e9;

vector<int> dijkstra(int &n, int start, vector<vector<pi>> &graph) {
    vector<int> dist(n + 1, INF);
    priority_queue<pi, vector<pi>, greater<>> pq;

    pq.push({0, start});
    dist[start] = 0;
    while (!pq.empty()) {
        int curr_dist = pq.top().first;
        int curr_node = pq.top().second;
        pq.pop();

        if (curr_dist > dist[curr_node]) {
            continue;
        }
        for (int i = 0; i < graph[curr_node].size(); i++) {
            int next_node = graph[curr_node][i].first;
            int next_dist = curr_dist + graph[curr_node][i].second;
            if (dist[next_node] > next_dist) {
                dist[next_node] = next_dist;
                pq.push({next_dist, next_node});
            }
        }
    }
    return dist;
}

/**
 * s->g, s->h, g->목적지 후보, h->목적지 후보 최단경로 구하고
 * s->목적지 후보 최단경로 구해서 위의 경우와 일치하는 경우
 */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case, n, m, t, s, g, h, a, b, d;

    cin >> test_case;
    while (test_case--) {
        cin >> n >> m >> t >> s >> g >> h;
        vector<vector<pi>> graph(n + 1, vector<pi>());
        vector<int> goal_candidate(t);
        while (m--) {
            cin >> a >> b >> d;
            graph[a].emplace_back(b, d);
            graph[b].emplace_back(a, d);
        }
        for (int i = 0; i < t; i++) {
            cin >> goal_candidate[i];
        }

        // s에서 시작하는 최단경로 구하기
        vector<int> dist_s = dijkstra(n, s, graph);
        // g에서 시작하는 최단경로 구하기
        vector<int> dist_g = dijkstra(n, g, graph);
        // h에서 시작하는 최단경로 구하기
        vector<int> dist_h = dijkstra(n, h, graph);

        // 목적지 후보별로 확인
        sort(goal_candidate.begin(), goal_candidate.end());
        for (int i = 0; i < t; i++) {
            int e = goal_candidate[i];
            // s->g->h->e, s->h->g->e 중 최단경로 구하기
            int temp_dist = min(dist_s[g] + dist_g[h] + dist_h[e], dist_s[h] + dist_h[g] + dist_g[e]);

            // g-h 거치는 경로와 s->e 의 최단경로가 같다면
            if (temp_dist == dist_s[e]) {
                cout << e << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}