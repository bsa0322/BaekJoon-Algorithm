#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e5 * 2;

vector<vector<int>> floyd(int n, vector<vector<int>> &graph, vector<vector<int>> path) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int d = graph[i][k] + graph[k][j];
                if (graph[i][j] > d) {
                    graph[i][j] = d;
                    path[i][j] = path[i][k]; //이 부분이 일반 역추적 문제랑 다르구만..
                }
            }
        }
    }
    return path;
}

int main() {
    int n, m, a, b, c;

    cin >> n >> m;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));
    vector<vector<int>> path(n + 1, vector<int>(n + 1, 0));
    while (m--) {
        cin >> a >> b >> c;
        graph[a][b] = graph[b][a] = c;
        path[a][b] = b;
        path[b][a] = a;
    }

    for (int i = 1; i <= n; i++)
        graph[i][i] = 0;

    path = floyd(n, graph, path);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (path[i][j])
                cout << path[i][j] << ' ';
            else
                cout << "- ";
        }
        cout << '\n';
    }

    return 0;
}