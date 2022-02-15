#include <iostream>
#include <vector>

using namespace std;

void f(int x, vector<vector<int>> &v, vector<int> &check) {
    for (int i = 0; i < v[x].size(); i++) {
        if (check[v[x][i]] == 0) {
            check[v[x][i]] = 3 - check[x];
            f(v[x][i], v, check);
        }
    }
}

bool answer(int x, vector<vector<int>> &v, vector<int> &check) {
    for (int i = 0; i < v[x].size(); i++) {
        if (check[v[x][i]] != (3 - check[x])) {
            return false;
        }
    }
    return true;
}

int main() {
    int t, n, m, a, b;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<vector<int>> v(n + 1, vector<int>(0));
        vector<int> check(n + 1, 0);
        while (m--) { //그래프 만들기
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        for (int i = 1; i <= n; i++) {
            if (check[i] == 0) { //방문 체크?
                check[i] = 1;
                f(i, v, check);
            }
        }
        bool result = true;
        for (int i = 1; i <= n; i++) {
            if (check[i] == 0 || !answer(i, v, check)) {
                result = false;
                break;
            }
        }
        if (result) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}