#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int SIZE = 3;

int main() {
    vector<int> num(SIZE);
    for (int i = 0; i < SIZE; i++) {
        cin >> num[i];
    }
    sort(num.begin(), num.end());
    cout << num[SIZE / 2];
    return 0;
}