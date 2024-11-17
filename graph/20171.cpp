//n개의 후보, k 개의 아파트 복합단지
//가능한 한 디저트 카페를 아파트랑 가깝게
//굿 플레이스 p는 다른 모든 후보들과 비교했을 때 더 가까운 아파트가 한개라도 존재하면 됨
//후보와 아파트가 주어졌을 때, 굿 플레이스를 찾아라
#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 1e5;

//일단 간선 n-1개니까 트리
//아파트 사이의 노드들이 굿 플레이스
//가중치 값은 상관 x

vector<bool> visited(SIZE + 1, false);
int answer = 0;

bool tree(int node, vector<vector<int>> &graph, vector<bool> &apart) {
    visited[node] = true;
    bool is_good = false;
    for (int i = 0; i < graph[node].size(); i++) {
        if (visited[graph[node][i]])
            continue;
        if (apart[graph[node][i]])
            is_good = true;
        if (tree(graph[node][i], graph, apart))
            is_good = true;
    }
    if (is_good || apart[node]) {
        answer++;
        return true;
    }
    return false;
}

int main() {
    int n, k, a, b, c;

    //입력
    cin >> n >> k;
    vector<vector<int>> graph(n + 1, vector<int>(0));
    vector<bool> apart(SIZE + 1, false);
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b >> c;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 0; i < k; i++) {
        cin >> a;
        apart[a] = true;
    }

    for (int i = 1; i <= n; i++) {
        if (apart[i]) { //아파트 발견
            tree(i, graph, apart);
            cout << answer << '\n';
            return 0;
        }
    }
}

