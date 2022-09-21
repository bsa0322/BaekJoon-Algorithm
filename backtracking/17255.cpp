//
// Created by BaeSuA on 2022-09-21.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

string n;
vector<int> frequency(10, 0);
map<string, bool> check;

int backtracking(int cnt, string num) {
    int result = 0;
//    cout << cnt << ": " << num << '\n';
    if (cnt == n.length()) {
//        cout << "--------------------\n";
        if (num == n) {
            return 1;
        }
        return 0;
    }
    for (int i = 0; i < 10; i++) {
        if (frequency[i]) {
            frequency[i]--;
            if (!check[num + to_string(i)]) {
                check[num + to_string(i)] = true;
                result += backtracking(cnt + 1, num + to_string(i));
            }
            if (!check[to_string(i) + num]) {
                check[to_string(i) + num] = true;
                result += backtracking(cnt + 1, to_string(i) + num);
            }
            frequency[i]++;
            check[num + to_string(i)] = false;
            check[to_string(i) + num] = false;
        }
    }
    return result;
}

/**
 * 사실상 범위는 8
 */

int main() {
    cin >> n;

    for (int i = 0; i < n.length(); i++) {
        frequency[n[i] - '0']++;
    }

    cout << backtracking(0, "");
    return 0;
}