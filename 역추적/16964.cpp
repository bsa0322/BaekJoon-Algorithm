#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<int> order; //입력 DFS 방문 순서 노드별 순서값 저장
vector<bool> visited;
vector<int> result; //dfs 방문 순서

bool cmp(const int &a, const int &b) {
    return order[a] < order[b];
}

void dfs(int x) {
    if (visited[x])
        return;
    visited[x] = true;
    result.push_back(x);
    for (int i = 0; i < graph[x].size(); i++)
        dfs(graph[x][i]);
}

int main() {
    int n, a, b, input;
    bool ans = true;

    cin >> n;
    graph.assign(n + 1, vector<int>(0));
    order.assign(n + 1, 0);
    visited.assign(n + 1, false);
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        cin >> input;
        order[input] = i;
    }
    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end(), cmp);
    }

    //연산
    dfs(1);
    for (int i = 0; i < n; i++) {
        if (order[result[i]] != i) {
            ans = false;
            break;
        }
    }
    cout << ans << '\n';

    return 0;
}