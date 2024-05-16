#include <iostream>
#include <vector>

using namespace std;
vector<bool> check;
vector<int> picked_num;

void simulation(int cnt, int s, int t, int &kk, int &sum) {
    if (cnt >= 1 && cnt <= kk) {
        check[s] = true;
        if (sum - 2 * s >= 0)
            check[sum - 2 * s] = true;
        if (cnt == kk) {
            return;
        }
    }
    for (int i = t; i < kk; i++) {
        simulation(cnt + 1, s + picked_num[i], i + 1, kk, sum);
    }
}

void sol(int cnt, int kk, int sum, int t, int &k, vector<int> &num) {
    if (cnt == kk) {
        simulation(0, 0, 0, kk, sum);
        return;
    }
    for (int i = t; i < k; i++) {
        picked_num[cnt] = num[i];
        sol(cnt + 1, kk, sum + num[i], i + 1, k, num);
    }
}


int main() {
    int k, total = 0;
    cin >> k;
    vector<int> num(k, 0);
    for (int i = 0; i < k; i++) {
        cin >> num[i];
        total += num[i];
    }
    check.assign(total + 1, false);
    check[total] = true;

    for (int i = 1; i <= k; i++) {
        picked_num.assign(i, 0);
        sol(0, i, 0, 0, k, num);
    }

    int ans = 0;
    for (int i = 1; i <= total; i++) {
        if (!check[i]) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}