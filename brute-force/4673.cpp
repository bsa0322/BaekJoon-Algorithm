#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 10000;

int main() {
    vector<bool> self_number(SIZE + 1, true);

    for (int i = 1; i <= SIZE; i++) {
        int sum = i;
        int k = i;
        while (k) {
            sum += (k % 10);
            k /= 10;
        }
        if (sum > SIZE) {
            continue;
        }
        self_number[sum] = false;
    }

    for (int i = 1; i <= SIZE; i++) {
        if (self_number[i]) {
            cout << i << '\n';
        }
    }
    return 0;
}