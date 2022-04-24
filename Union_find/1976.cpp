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
    int n, m, a, b;

    //입력
    cin >> n >> m;
    vector<vector<int>> board(n + 1, vector<int>(n + 1, 0));
    parent.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (board[i][j])
                u(i, j);
        }
    }

    cin >> a;
    while (--m) {
        cin >> b;
        if (find(a) != find(b)) {
            cout << "NO\n";
            return 0;
        }
        a = b;
    }
    cout << "YES\n";
    return 0;
}