//
// Created by BaeSuA on 2022-09-07.
//

#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int n;

    cin >> n;
    vector<int> ring(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> ring[i];
    }
    for (int i = 1; i < n; i++) {
        int g = gcd(ring[0], ring[i]);
        cout << ring[0] / g << '/' << ring[i] / g << '\n';
    }
    return 0;
}