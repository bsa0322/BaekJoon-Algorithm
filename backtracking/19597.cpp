//
// Created by BaeSuA on 2022-04-25.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
bool flag;
vector<int> rev_str;
vector<string> str, temp;

void backtracking(int cnt) {
    if (cnt == n) {
        flag = true;
        return;
    }
    for (int i = 0; i < 2; i++) {
        string s = str[cnt];
        if (i) { // reverse 하는 경우
            reverse(s.begin(), s.end());
        }
        if (cnt == 0) {
            temp[cnt] = s;
            rev_str[cnt] = i;
            backtracking(cnt + 1);
            if (flag) {
                return;
            }
            temp[cnt] = "";
            rev_str[cnt] = 0;
        } else if (temp[cnt - 1] < s) { //사전 순일 경우만
            temp[cnt] = s;
            rev_str[cnt] = i;
            backtracking(cnt + 1);
            if (flag) {
                return;
            }
            temp[cnt] = "";
            rev_str[cnt] = 0;
        }
    }
}

int main() {
    int t;

    //입력
    cin >> t;
    while (t--) {
        cin >> n;
        rev_str.assign(n, 0);
        str.assign(n, "");
        temp.assign(n, "");
        for (int i = 0; i < n; i++) {
            cin >> str[i];
        }

        flag = false;
        backtracking(0);
        for (int i = 0; i < n; i++) {
            cout << rev_str[i];
        }
        cout << '\n';
    }
    return 0;
}