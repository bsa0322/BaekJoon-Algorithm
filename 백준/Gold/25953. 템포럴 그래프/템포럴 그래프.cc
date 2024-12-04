#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci;
typedef pair<ci, int> pi;
const int INF = 2e9;

int getMinimumDist(int &n, int &t, int &m, int &s, int &e, vector<vector<pi>> &graph) {
    vector<vector<int>> dist(t + 1, vector<int>(n, INF));
    int ans = INF;

    // 시작 정점 초기화
    dist[0][s] = 0;

    // 시간 1부터 t까지 모든 간선에 대해 dist 배열 업데이트
    for (int i = 1; i <= t; i++) {
        // 이전 시간의 정보로 초기화
        for (int j = 0; j < n; j++) {
            dist[i][j] = dist[i - 1][j];
        }
        for (int j = 0; j < m; j++) {
            int a = graph[i][j].first.first;
            int b = graph[i][j].first.second;
            int c = graph[i][j].second;

            dist[i][a] = min(dist[i][a], min(dist[i - 1][a], dist[i - 1][b] + c));
            dist[i][b] = min(dist[i][b], min(dist[i - 1][b], dist[i - 1][a] + c));
            if (a == e) {
                ans = min(ans, dist[i][a]);
            } else if (b == e) {
                ans = min(ans, dist[i][b]);
            }
        }
    }

    return (ans == INF ? -1 : ans);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, t, m, s, e;
    cin >> n >> t >> m >> s >> e;
    vector<vector<pi>> graph(t + 1, vector<pi>(m)); // 시간별로 그래프 정보 {정점1, 정점2, 가중치} 리스트 형태로 저장
    for (int i = 1; i <= t; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j].first.first >> graph[i][j].first.second >> graph[i][j].second;
        }
    }

    cout << getMinimumDist(n, t, m, s, e, graph);
    return 0;
}