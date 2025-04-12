#include <iostream>
#include <vector>

using namespace std;

int cnt1 = 1, cnt2;

int fib(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    cnt1++;
    return fib(n - 1) + fib(n - 2);
}

int fibonacci(int n) {
    vector<int> f(n + 1);
    f[1] = f[2] = 1;
    for (int i = 3; i <= n; i++) {
        cnt2++;
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}

int main() {
    int n;
    cin >> n;
    fib(n);
    fibonacci(n);
    cout << cnt1 << ' ' << cnt2;
    return 0;
}