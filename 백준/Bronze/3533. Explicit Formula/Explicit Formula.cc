#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 10;

int ans = 0b0;
vector<int> num(SIZE, 0b0);

void backtracking(int cnt, int t, int sum, int &target) {
    if (cnt == target) {
        ans ^= sum;
        return;
    }
    for (int i = t; i < SIZE; i++) {
        int new_sum = sum | num[i];
        backtracking(cnt + 1, i + 1, new_sum, target);
    }
}

int main() {
    for (int i = 0; i < SIZE; i++) {
        cin >> num[i];
    }
    // 조합 개수
    for (int i = 2; i <= 3; i++) {
        backtracking(0, 0, 0b0, i);
    }
    cout << ans;
    return 0;
}