//
// Created by BaeSuA on 2022-11-07.
//

#include <iostream>
#include <stack>

using namespace std;

bool solution(string &s) {
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push(s[i]);
        } else {
            if (st.empty()) {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << (solution(s) ? "YES" : "NO") << '\n';
    }
    return 0;
}