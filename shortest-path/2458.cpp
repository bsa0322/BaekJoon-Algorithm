//
// Created by BaeSuA on 2022-12-19.
//

#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e9;

void floyd(int n, vector<vector<int>> &graph) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j] = min(graph[i][k] + graph[k][j], graph[i][j]);
            }
        }
    }
}

int solution(int n, vector<vector<int>> &graph) {
    vector<int> cnt(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] != INF) {
                cnt[i]++;
                cnt[j]++;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (cnt[i] == n - 1) {
            ans++;
        }
    }
    return ans;
}

/**
 * 자신의 키가 몇 번째인지 알 수 있는 학생들은 몇명인지
 * 플로이드-워샬로 경로 구한 후, 어떤 정점 x에 대해 [][x]의 개수와 [x][]의 개수를 합한 것이 n-1인 경우 자신의 위치를 알 수 있는 것!
 */

int main() {
    int n, m, a, b;

    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(n, INF));
    while (m--) {
        cin >> a >> b;
        graph[a - 1][b - 1] = 1;
    }

    floyd(n, graph);
    cout << solution(n, graph);
    return 0;
}