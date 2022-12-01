//
// Created by BaeSuA on 2022-12-01.
//

/**
* 최악, 최소 간의 피로도 차이
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <cmath>

using namespace std;
typedef tuple<int, int, int> tp;

vector<int> parent;

int findParent(int x) {
    if (parent[x] < 0) {
        return x;
    }
    return parent[x] = findParent(parent[x]);
}

bool unionInput(int x, int y) {
    int par_x = findParent(x);
    int par_y = findParent(y);

    if (par_x == par_y) {
        return false;
    }

    if (parent[par_x] > parent[par_y]) { // par_y가 새로운 부모
        parent[par_y] += parent[par_x];
        parent[par_x] = par_y;
    } else {
        parent[par_x] += parent[par_y];
        parent[par_y] = par_x;
    }
    return true;
}

int kruskal(int n, vector<tp> &edges) {
    int cnt = 0;
    int sum = 0;
    int idx = 0;
    while (cnt < n) {
        int c = get<0>(edges[idx]);
        int a = get<1>(edges[idx]);
        int b = get<2>(edges[idx]);
        idx++;

        if (!unionInput(a, b)) {
            continue;
        }
        cnt++;
        sum += c;
    }
    return sum;
}

int main() {
    int n, m, a, b, c;

    cin >> n >> m;
    vector<tp> edges;
    parent.assign(n + 1, -1);
    m++;
    while (m--) {
        cin >> a >> b >> c;
        edges.push_back({!c, a, b});
    }

    // 최적
    sort(edges.begin(), edges.end(), greater<>());
    int max_cost = pow(kruskal(n, edges), 2);
    sort(edges.begin(), edges.end());
    parent.assign(n + 1, -1);
    int min_cost = pow(kruskal(n, edges), 2);

    // 출력
    cout << max_cost - min_cost;
    return 0;
}