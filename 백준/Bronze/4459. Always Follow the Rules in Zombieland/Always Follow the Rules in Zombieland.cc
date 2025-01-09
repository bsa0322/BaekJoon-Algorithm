#include <iostream>
#include <map>

using namespace std;

int main() {
    int q, r, rule_num;
    string rule;
    map<int, string> rules;
    cin >> q;
    for (int i = 0; i <= q; i++) {
        getline(cin, rule);
        if (i == 0) {
            continue;
        }
        rules[i] = rule;
    }
    cin >> r;
    while (r--) {
        cin >> rule_num;
        cout << "Rule " << rule_num << ": ";
        if (rules[rule_num] == "") {
            cout << "No such rule";
        } else {
            cout << rules[rule_num];
        }
        cout << '\n';
    }
    return 0;
}