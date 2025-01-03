#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int a, b, n;
    cin >> a >> b >> n;
    vector<int> heights;
    a *= n;
    for (int i = 1; i <= n; i++) {
        int h = i * b + a;
        heights.push_back(h);
    }
    sort(heights.begin(), heights.end());
    for (auto h: heights) {
        cout << h << ' ';
    }
    return 0;
}