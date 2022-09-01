//
// Created by BaeSuA on 2022-09-01.
//

#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n;
    string name, cmd;
    set<string> company;

    cin >> n;
    while (n--) {
        cin >> name >> cmd;
        if (cmd == "enter") {
            company.insert(name);
        } else {
            company.erase(name);
        }
    }

    for (auto iter = company.rbegin(); iter != company.rend(); iter++) {
        cout << *iter << '\n';
    }
    return 0;
}