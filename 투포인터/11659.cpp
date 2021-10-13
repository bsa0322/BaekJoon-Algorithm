#include<iostream>

using namespace std;
int sum[100010];

int main() {
    cin.tie(0);
    int n, m, i, a, s, e;
    cin >> n >> m;
    for (i = 1; i <= n; i++) {
        cin >> a;
        sum[i] += sum[i - 1] + a;
    }
    for (i = 0; i < m; i++) {
        cin >> s >> e;
        cout << sum[e] - sum[s - 1] << '\n';
    }
    return 0;
}