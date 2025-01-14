#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, s, a, max_a = 0;
    cin >> n >> s;
    while (n--) {
        cin >> a;
        max_a = max(a, max_a);
    }
    cout << ceil((float) max_a * s / 1000);
    return 0;
}