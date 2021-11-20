#include <iostream>
#include <vector>

using namespace std;

vector<int> parent, fact_people;

int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void u(int a, int b) {
    int a_par = find(a);
    int b_par = find(b);
    if (a_par != b_par && fact_people[a_par])
        parent[b_par] = a_par;
    else if (a_par != b_par && fact_people[b_par])
        parent[a_par] = b_par;
    else
        parent[a_par] = b_par;
}

/**
 * 진실을 아는 사람이 있을 경우, 합집합
 * 과장된 이야기 할 수 있는 파티는 진실 아는 사람이 한 명도 없는 파티
 * 우선 모든 입력을 받아서 서로소 집합의 개수를 셈
 */

int main() {
    int n, m, fact, p, a, b;

    //입력
    cin >> n >> m >> fact;
    parent.assign(n + 1, 0);
    fact_people.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    while (fact--) {
        cin >> a;
        fact_people[a] = 1;
    }
    vector<vector<int>> party(m, vector<int>(0));
    for (int i = 0; i < m; i++) {
        cin >> p >> a;
        party[i].push_back(a);
        while (--p) {
            cin >> b;
            u(a, b);
            a = b;
            party[i].push_back(a);
        }
    }
    int ans = m;
    for (int i = 0; i < m; i++) {
        bool check = false;
        for (int j = 0; j < party[i].size(); j++) {
            if (fact_people[find(party[i][j])]) {
                check = true;
                break;
            }
        }
        if (check)
            ans--;
    }

    cout << ans << '\n';
    return 0;
}