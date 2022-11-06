//
// Created by BaeSuA on 2022-11-06.
//

#include <iostream>
#include <vector>

using namespace std;

pair<int, int> solution(int m, int n) {
    int sum = 0, min_value = 0;
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if(!is_prime[i]){
            continue;
        }
        if (i >= m) {
            sum += i;
            if (!min_value) {
                min_value = i;
            }
        }
        for (int j = i * i; j <= n; j += i) {
            is_prime[j] = false;
        }
    }
    return {sum, min_value};
}

int main() {
    int m, n;
    cin >> m >> n;

    pair<int, int> ans = solution(m, n);

    if (ans.first == 0) {
        cout << "-1\n";
        return 0;
    }
    cout << ans.first << '\n' << ans.second;
    return 0;
}