#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int> ci;

vector<vector<int>> matrix;

int dijkstrea(int n, int st, int ed) {
    vector<int> dist(n + 1, -1);
    priority_queue<ci, vector<ci>, greater<ci>> pq; //first:거리, second: 노드
    dist[st] = 0;
    pq.push(ci(0, st));
    while (!pq.empty()) {
        int node = pq.top().second;
        pq.pop();

        for (int i = 1; i <= n; i++) {
            if (matrix[node][i] == 0)
                continue;
            if (dist[i] == -1 || dist[i] > dist[node] + matrix[node][i]) {
                dist[i] = dist[node] + matrix[node][i];
                pq.push(ci(dist[i], i));
            }
        }
    }
    return dist[ed];
}

int main() {
    int n, e, a, b, c, v1, v2, ans = -1, sum1 = 0, sum2 = 0;

    //입력
    cin >> n >> e;
    matrix.assign(n + 1, vector<int>(n + 1, 0));
    while (e--) {
        cin >> a >> b >> c;
        matrix[a][b] = matrix[b][a] = c;
    }
    cin >> v1 >> v2;

    //연산
    int d1 = dijkstrea(n, 1, v1);
    int d2 = dijkstrea(n, v1, v2);
    int d3 = dijkstrea(n, v2, n);
    if (d1 != -1 && d2 != -1 && d3 != -1)
        sum1 = d1 + d2 + d3;
    d1 = dijkstrea(n, 1, v2);
    d3 = dijkstrea(n, v1, n);
    if (d1 != -1 && d2 != -1 && d3 != -1)
        sum2 = d1 + d2 + d3;
    if (sum1 && sum2)
        ans = min(sum1, sum2);
    else if (sum1)
        ans = sum1;
    else if (sum2)
        ans = sum2;

    //출력
    cout << ans << '\n';

    return 0;
}