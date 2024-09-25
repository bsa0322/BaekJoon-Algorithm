#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n, w;
    cin >> n >> w;
    vector<long long> coin(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }

    if (n == 1) {
        cout << w;
        return 0;
    }

    long long min_coin = -1;
    bool is_up = coin[0] < coin[1];
    if (is_up) {
        min_coin = coin[0];
    }

    for (int i = 1; i < n - 1; i++) {
        if (is_up && coin[i] > coin[i + 1]) {
            is_up = false;
            long long coin_cnt = w / min_coin;
            w %= min_coin;
            w += coin_cnt * coin[i];
            min_coin = -1;
        } else if (!is_up && coin[i] < coin[i + 1]) {
            min_coin = coin[i];
            is_up = true;
        }
    }

    if (is_up && min_coin != -1) {
        long long coin_cnt = w / min_coin;
        w %= min_coin;
        w += coin_cnt * coin[n - 1];
    }

    cout << w;

    return 0;
}