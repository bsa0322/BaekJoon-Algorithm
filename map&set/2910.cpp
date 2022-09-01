//
// Created by BaeSuA on 2022-09-01.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
typedef pair<int, int> ci;
map<int, int> mp, order;

bool cmp(const ci &a, const ci &b) {
    if (a.second != b.second) {
        return a.second > b.second;
    }
    return order[a.first] < order[b.first];
}

int main() {
    int n, c, num;

    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> num;
        mp[num]++;
        if (order.find(num) == order.end()) {
            order[num] = i;
        }
    }

    // map -> vector
    vector<pair<int, int>> v(mp.begin(), mp.end());
    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].second; j++) {
            cout << v[i].first << ' ';
        }
    }
    return 0;
}