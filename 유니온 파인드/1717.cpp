#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int find(int a) {
    if (parent[a] == a)
        return a;
    return parent[a] = find(parent[a]);
}

void sum(int a, int b) {
    int a_par = find(a);
    int b_par = find(b);
    if (a_par != b_par)
        parent[b_par] = a_par;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, q, a, b;

    //입력
    cin >> n >> m;
    parent.assign(n + 1, 0);
    //parent 초기화
    for (int i = 0; i <= n; i++)
        parent[i] = i;
    while (m--) {
        cin >> q >> a >> b;
        if (q) { //서로 같은 집합인지 확인
            if (find(a) == find(b))
                cout << "YES\n";
            else
                cout << "NO\n";
        } else { //합집합
            sum(a, b);
        }
    }
//    for (int i = 0; i <= n; i++)
//        cout << parent[i] << ' ';
    return 0;
}