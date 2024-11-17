//
// Created by BaeSuA on 2022-11-02.
//

// k 범위가 작다.. 그럼 진짜 다 해봐도 될듯!!

#include <iostream>
#include <vector>

using namespace std;

vector<string> number = {"1111110", "0110000", "1101101", "1111001", "0110011", "1011011", "1011111", "1110000",
                         "1111111", "1111011"};

int countDiff(int k, int num1, int num2) {
    int cnt = 0;
    while (k--) {
        int temp1 = num1 % 10;
        int temp2 = num2 % 10;
        for (int i = 0; i < 8; i++) {
            if (number[temp1][i] != number[temp2][i]) {
                cnt++;
            }
        }
        num1 /= 10;
        num2 /= 10;
    }
    return cnt;
}

int main() {
    int n, k, p, x;

    cin >> n >> k >> p >> x;

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (x == i) {
            continue;
        }
        int change_cnt = countDiff(k, x, i);
        if (change_cnt <= p) {
            ans++;
        }
    }

    cout << ans;
    return 0;
}