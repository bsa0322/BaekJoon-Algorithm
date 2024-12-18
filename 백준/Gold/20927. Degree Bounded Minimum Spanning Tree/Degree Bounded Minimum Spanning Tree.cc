#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
const int INF = 2e9;
typedef tuple<int, int, int> tp;

int min_cost = INF;
vector<int> min_edges;
vector<int> temp_edges;

int getParent(int x, vector<int> &parent) {
    if (parent[x] < 0) {
        return x;
    }
    return parent[x] = getParent(parent[x], parent);
}

// 이미 union 되어 있다면 false 리턴
bool unionEdge(int x, int y, vector<int> &parent) {
    int x_par = getParent(x, parent);
    int y_par = getParent(y, parent);

    if (x_par == y_par) {
        return false;
    }
    if (parent[x_par] < parent[y_par]) {
        parent[x_par] += parent[y_par];
        parent[y_par] = x_par;
    } else {
        parent[y_par] += parent[x_par];
        parent[x_par] = y_par;
    }
    return true;
}

int getCost(int &n, vector<int> &b, vector<tp> &edges) {
    vector<int> parent(n + 1, -1);
    vector<int> degree(n + 1, 0);
    int cost = 0;
    for (auto e_idx: temp_edges) {
        int x = get<0>(edges[e_idx]);
        int y = get<1>(edges[e_idx]);
        int c = get<2>(edges[e_idx]);
        if (!unionEdge(x, y, parent)) {
            // 트리 만들 수 없음
            return INF;
        }
        degree[x]++;
        degree[y]++;
        cost += c;
    }
    for (int i = 1; i <= n; i++) {
        if (degree[i] > b[i]) {
            // i번 정점의 차수가 b를 넘어감
            return INF;
        }
    }
    return cost;
}

void solution(int cnt, int t, int &n, int &m, vector<int> &b, vector<tp> &edges) {
    if (cnt == n - 1) {
        // 차수가 b를 넘지 않으면서 트리 만드는지 확인
        int cost = getCost(n, b, edges);

        // 간선 합 최소 갱신
        if (min_cost > cost) {
            min_cost = cost;
            min_edges = temp_edges;
        }
        return;
    }
    // n-1개 간선 고르기
    for (int i = t; i < m; i++) {
        temp_edges[cnt] = i;
        solution(cnt + 1, i + 1, n, m, b, edges);
    }
}

int main() {
    int n, m, x, y, c;
    cin >> n >> m;
    vector<int> b(n + 1, 0); // 각 정점마다 조건 차수
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    vector<tp> edges(m); // 간선 정보
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> c;
        edges[i] = {x, y, c};
    }

    // 최소 스패닝 트리 이루는 간선 정보 초기화
    min_edges.assign(n - 1, 0);
    temp_edges.assign(n - 1, 0);

    solution(0, 0, n, m, b, edges);
    if (min_cost != INF) {
        cout << "YES\n";
        for (auto e_idx: min_edges) {
            cout << get<0>(edges[e_idx]) << ' ' << get<1>(edges[e_idx]) << '\n';
        }
    } else {
        cout << "NO";
    }
    return 0;
}