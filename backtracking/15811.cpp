//
// Created by BaeSuA on 2022-09-20.
//

// 문자를 숫자로 바꿨을 때 식이 성립하나. 답이 존재하나. 여부 출력
// 가지치기 어디서 할까,,,,,, 일단 일의자리부터 계산하면서 안되면 바로 컷 ? -> 구현 너무 복잡
// 존재하는 알파벳 내에서 0 ~ 9 까지 배치 모든 경우 해보고,,,마지막에 더하기!
// 범위는 18.. 백트래킹 가능!

/**
 * stoll 로 string to long long 하면 시간초과남.......시간이 꽤 걸리나봄
 * 반복문으로 10씩 곱하며 해결해야함..
 *
 */


#include <iostream>
#include <vector>

using namespace std;

vector<int> alpha(26, -2);
vector<bool> check(10, false);
string word1, word2, word3;

void checkString(string &s) {
    for (int i = 0; i < s.length(); i++) {
        alpha[s[i] - 'A'] = -1;
    }
}

long long stringToInt(string &s) {
    long long num = 0;
    for (int i = 0; i < s.length(); i++) {
        num = num * 10 + alpha[s[i] - 'A'];
    }
    return num;
}

bool f(int cnt) {
    bool ans = false;
    if (cnt == 26) {
        if (stringToInt(word1) + stringToInt(word2) == stringToInt(word3)) {
            return true;
        }
        return false;
    }
    if (alpha[cnt] == -2) {
        return f(cnt + 1);
    }
    for (int i = 0; i < 10; i++) {
        if (!check[i]) {
            check[i] = true;
            alpha[cnt] = i;
            ans = f(cnt + 1);
            if (ans) {
                return true;
            }
            check[i] = false;
            alpha[cnt] = -1;
        }
    }
    return ans;
}

int main() {
    cin >> word1 >> word2 >> word3;

    checkString(word1);
    checkString(word2);
    checkString(word3);

    cout << (f(0) ? "YES" : "NO");

    return 0;
}
