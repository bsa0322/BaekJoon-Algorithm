//
// Created by BaeSuA on 2022-09-10.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool isEqual(string &a, string &b) {
    if (a.length() != b.length()) {
        return false;
    }
    int leng = a.length();
    for (int i = 0; i < leng; i++) {
        for (int j = 0; j < leng; j++) {
            if (a[i] != b[j]) {
                continue;
            }
            int si = i, sj = j;
            bool chk = true;
            while (++si && ++sj) {
                si %= leng;
                sj %= leng;
                if (si == i) {
                    break;
                }
                if (a[si] != b[sj]) {
                    chk = false;
                    break;
                }
            }
            if (chk) {
                return true;
            }
        }
    }
    return false;
}

int diffWords(int n, vector<string> &words) {
    set<string> s;
    for (int i = 0; i < n; i++) {
        bool chk = false;
        for (auto x: s) {
            if (isEqual(x, words[i])) {
                chk = true;
                break;
            }
        }
        if (!chk) {
            s.insert(words[i]);
        }
    }
    return s.size();
}

int main() {
    int n;

    // 입력
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    // 연산 & 출력
    cout << diffWords(n, words);
    return 0;
}