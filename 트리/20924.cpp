#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;

ci findGiga(vector<vector<ci>> &graph, int n, int r) {
    queue<int> q;
    vector<int> visited(n + 1, -1);
    int height = -1, max_branch = 0, leng = 0;

    q.push(r);
    visited[r] = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        leng = visited[node];
        if (height == -1 && ((node == r && graph[node].size() >= 2) || (node != r && graph[node].size() > 2))) {
            height = leng;
            leng = 0;
        }
        if (height != -1)
            max_branch = max(max_branch, leng);

        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i].first;
            if (visited[next_node] == -1) {
                q.push(next_node);
                visited[next_node] = leng + graph[node][i].second;
            }
        }
    }
    if (height == -1) //자식 2개 이상 없었다면
        height = leng;
    return {height, max_branch};
}

int main() {
    int n, r, a, b, d;

    //입력
    cin >> n >> r;
    vector<vector<ci>> graph(n + 1, vector<ci>(0));
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b >> d;
        graph[a].push_back({b, d});
        graph[b].push_back({a, d});
    }

    //연산
    ci ans = findGiga(graph, n, r);

    //출력
    cout << ans.first << ' ' << ans.second << '\n';
}