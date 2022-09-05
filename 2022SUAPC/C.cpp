//
// Created by BaeSuA on 2022-09-04.
//

#include <iostream>
#include <vector>

using namespace std;

// 4->1, 2->4, 3-> 2, 3
int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << '\n';
        return 0;
    }
    if (n % 2 == 1) {
        cout << -1;
        return 0;
    }
    vector<int> people(n, 0), ans;
    int cnt = 1;
    for (int i = 0; i < n; i += 2) {
        people[i] = cnt++;
    }
    for (int i = n - 1; i > 0; i -= 2) {
        people[i] = cnt++;
    }
//    for(int i=0;i<n;i++){
//        cout<<people[i]<<' ';
//    }

    ans.push_back(n);
    for (int i = 1; i < n; i++) {
        ans.push_back((people[i] - people[i - 1] + n) % n);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}