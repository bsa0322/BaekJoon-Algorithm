#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, c;
    queue<int> q;

    cin >> n;
    vector<int> sq(n);
    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> sq[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        if (!sq[i]) { //큐만 집어넣기
            q.push(num[i]);
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> c;
        q.push(c);
        cout << q.front() << ' ';
        q.pop();
    }
    return 0;
}