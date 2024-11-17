#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<int> dp;

int makeTree(int node, int parent) {
    if (dp[node] != 0)
        return dp[node];
    dp[node] = 1;
    for (int i = 0; i < graph[node].size(); i++) {
        if (graph[node][i] != parent) {
            dp[node] += makeTree(graph[node][i], node);
        }
    }
    return dp[node];
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int n, r, q, u, v;

    cin >> n >> r >> q;
    graph.assign(n + 1, vector<int>(0));
    dp.assign(n + 1, 0);
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    //연산
    int root = makeTree(r, -1);

    //출력
    while (q--) {
        cin >> u;
        cout << dp[u] << '\n';
    }

    return 0;
}