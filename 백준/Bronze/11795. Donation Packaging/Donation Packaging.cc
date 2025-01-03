#include <iostream>

using namespace std;

int main() {
    int t, a, b, c, sum_a = 0, sum_b = 0, sum_c = 0;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        sum_a += a;
        sum_b += b;
        sum_c += c;
        int min_num = min(sum_a, min(sum_b, sum_c));
        if (min_num < 30) {
            cout << "NO";
        } else {
            cout << min_num;
            sum_a -= min_num;
            sum_b -= min_num;
            sum_c -= min_num;
        }
        cout << '\n';
    }
    return 0;
}