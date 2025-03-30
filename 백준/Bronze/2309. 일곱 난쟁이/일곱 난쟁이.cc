#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int NUM = 9;
const int ANS_SIZE = 7;
vector<int> heights(NUM);
vector<int> temp(ANS_SIZE);
vector<int> ans(ANS_SIZE);

void backtracking(int cnt, int t, int sum) {
    if (cnt == ANS_SIZE) {
        if (sum == 100) {
            ans = temp;
        }
        return;
    }
    for (int i = t; i < NUM; i++) {
        temp[cnt] = heights[i];
        backtracking(cnt + 1, i + 1, sum + heights[i]);
    }
}

int main() {
    for (int i = 0; i < NUM; i++) {
        cin >> heights[i];
    }
    backtracking(0, 0, 0);
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ANS_SIZE; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}