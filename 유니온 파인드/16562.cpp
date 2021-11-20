#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;

vector<int> parent;

int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void u(int a, int b) {
    int a_par = find(a);
    int b_par = find(b);
    if (a_par != b_par)
        parent[a_par] = b_par;
}

int main() {
    int n, m, k, a, b, input;

    //입력
    cin >> n >> m >> k;
    priority_queue<ci, vector<ci>, greater<>> pq;
    parent.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> input;
        pq.push({input, i});
        parent[i] = i;
    }
    while (m--) {
        cin >> a >> b;
        u(a, b);
    }
    int ans = 0;
    vector<bool> check(n + 1, 0);
    while (!pq.empty()) {
        int money = pq.top().first;
        int f = pq.top().second;
        pq.pop();
        if (ans > k) {
            cout << "Oh no\n";
            return 0;
        }
        if (!check[find(f)]) {
            ans += money;
            check[find(f)] = true;
        }
    }
    cout << ans << '\n';
    return 0;
}