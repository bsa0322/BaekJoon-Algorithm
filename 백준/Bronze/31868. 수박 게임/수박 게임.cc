#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    cout << (k / (1 << (n - 1)));
    return 0;
}