#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
const int SIZE = 6e4;

int main() {
    vector<int> results(SIZE + 1, 0); // 0: perfect, 1: deficient, 2: abundant
    vector<string> names = {"PERFECT", "DEFICIENT", "ABUNDANT"};
    // SIZE 까지 우선 다 구해놓기
    for (int i = 1; i <= SIZE; i++) {
        int sum = 0;
        for (int j = 1; j <= sqrt(i); j++) {
            if (i % j != 0) {
                continue;
            }
            if (j != i) {
                sum += j;
            }
            int other = i / j;
            if (other != i) {
                sum += other;
            }
        }
        if (sum < i) {
            results[i] = 1;
        } else if (sum > i) {
            results[i] = 2;
        }
    }

    int n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        cout << n << ' ' << names[results[n]] << '\n';
    }
    return 0;
}