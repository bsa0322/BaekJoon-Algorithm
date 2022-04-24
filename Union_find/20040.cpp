#include <iostream>
#include <vector>

using namespace std;

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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, a, b;

    //입력
    cin >> n >> m;
    parent.assign(n, 0);
    for (int i = 0; i < n; i++)
        parent[i] = i;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        if (find(a) == find(b)) {
            cout << i << '\n';
            return 0;
        }
        u(a, b);
    }
    cout << "0\n";
    return 0;
}