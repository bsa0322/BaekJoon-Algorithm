//
// Created by BaeSuA on 2022-09-04.
//

#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci;

int main() {
    int n;
    cin >> n;
    vector<int> like(n, 0);
    vector<int> cnt(n, 0);
    vector<ci> editor(n);
    for (int i = 0; i < n; i++) {
        cin >> editor[i].first >> editor[i].second;
        // 더 개수 작은 쪽 선택
        if (editor[i].first > editor[i].second) {
            cnt[i] = editor[i].second;
        } else {
            cnt[i] = editor[i].first;
        }
    }
    return 0;
}