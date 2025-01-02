#include <iostream>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    int ans = 2;
    int x_sum = x, y_sum = y;
    while (x_sum + x > y_sum) {
        x_sum += x;
        y_sum += y;
        ans++;
    }
    cout << ans;
    return 0;
}