#include <iostream>
#include <vector>

using namespace std;

int stealMoney(int &n, int &m, int &k, vector<int> &num) {
    int ans = 0, sum = 0;
    for (int i = 0; i < m; i++)
        sum += num[i];

    if (sum < k)
        ans++;

    if (n != m) {
        for (int i = 0; i < n - 1; i++) {
            sum -= num[i];
            sum += num[(i + m) % n];
            if (sum < k)
                ans++;
        }
    }
    return ans;
}

int main() {
    int t, n, m, k;

    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        vector<int> num(n, 0);
        for (int i = 0; i < n; i++)
            cin >> num[i];

        cout << stealMoney(n, m, k, num) << '\n';
    }
    return 0;
}