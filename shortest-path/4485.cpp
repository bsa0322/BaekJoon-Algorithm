#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
typedef pair<int, ci> c;

int dijkstrea(int n, vector<vector<int>> &matrix) {
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    priority_queue<c, vector<c>, greater<c>> pq;
    pq.push(c(matrix[0][0], ci(0, 0)));
    matrix[0][0] = -1;
    while (!pq.empty()) {
        int d = pq.top().first;
        int cr = pq.top().second.first;
        int cc = pq.top().second.second;
        pq.pop();
        if (cr == n - 1 && cc == n - 1)
            return d;
        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < n && matrix[nr][nc] != -1) {
                pq.push(c(d + matrix[nr][nc], ci(nr, nc)));
                matrix[nr][nc] = -1;
            }
        }
    }
}

int main() {
    int n;
    for (int k = 1;; k++) {
        cin >> n;
        if (!n)
            break;
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> matrix[i][j];

        cout << "Problem " << k << ": " << dijkstrea(n, matrix) << '\n';
    }
    return 0;
}