#include<iostream>

using namespace std;
int num[10000000];
int check[10000000];

int main() {
    int n, p = 0, answer = 0, i, j, sum = 0, r = 0, l = 0;
    cin >> n;
    for (i = 2; i <= n; i++) {
        if (check[i] == 0) {
            num[p++] = i;
        }
        for (j = 2;; j++) {
            if (i * j > n) break;
            check[i * j] = 1;
        }
    }
    sum = num[0];
    while (1) {
        if (r >= p || l >= p) break;
        if (sum == n) {
            answer++;
            r++;
            sum += num[r];
        } else if (sum < n) {
            r++;
            sum += num[r];
        } else if (sum > n) {
            sum -= num[l];
            l++;
        }
    }
    cout << answer << '\n';
    return 0;
}