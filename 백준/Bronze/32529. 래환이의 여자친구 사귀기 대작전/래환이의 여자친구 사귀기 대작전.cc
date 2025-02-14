#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    int total = 0;
    for (int i = n - 1; i >= 0; i--) {
        total += num[i];
        if (total >= m) {
            cout << i + 1;
            return 0;
        }
    }
    cout << -1;
    return 0;
}