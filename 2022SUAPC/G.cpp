//
// Created by BaeSuA on 2022-09-04.
//

#include <iostream>
#include <vector>

using namespace std;
const int MAX = 1e6;

int main() {
    int n, k, tmp;
    cin >> n >> k;

    vector<int> xor_list(3 * MAX + 1, 0);
    vector<int> and_list;
    vector<int> or_list;
    int r0 = 0, r1 = 0, r2 = 0;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (xor_list[tmp ^ k]) {
            r2++;
        }
        xor_list[tmp]++;
        if ((tmp & k) == k) {
            and_list.push_back(tmp);
        }
        if ((tmp | k) == k) {
            or_list.push_back(tmp);
        }
    }

    for (int i = 0; i < and_list.size(); i++) {
        for (int j = i + 1; j < and_list.size(); j++) {
            if (k == (and_list[i] & and_list[j])) {
                r0++;
            }
        }
    }
    for (int i = 0; i < or_list.size(); i++) {
        for (int j = i + 1; j < or_list.size(); j++) {
            if (k == (or_list[i] | or_list[j])) {
                r1++;
            }
        }
    }

    cout << r0 << ' ' << r1 << ' ' << r2;
    return 0;
}