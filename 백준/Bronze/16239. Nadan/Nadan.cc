#include <iostream>

using namespace std;

int main() {
    int k, n;
    cin >> k >> n;
    for (int i = 1; i < n; i++) {
        cout << i << '\n';
        k -= i;
    }
    cout << k;
    return 0;
}