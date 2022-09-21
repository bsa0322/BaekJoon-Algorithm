//
// Created by BaeSuA on 2022-09-20.
//

// 문자를 숫자로 바꿨을 때 식이 성립하나. 답이 존재하나. 여부 출력
// 가지치기 어디서 할까,,,,,, 일단 일의자리부터 계산하면서 안되면 바로 컷
// 범위는 18.. 백트래킹 가능!

#include <iostream>
#include <vector>

using namespace std;

vector<int> alphabet(26, -1);
string word1, word2, word3;
int n;
bool ans = false;

void backtracking(int cnt) {
    if (cnt == 26) {
        int p1 = word1.length(), p2 = word2.length(), p3 = word3.length() - 1;
        bool carry = false;
        while (p1-- && p2--) {
            int num = carry + alphabet[word1[p1] - 'A'] + alphabet[word2[p2] - 'A'];
            if (num >= 10) {
                num %= 10;
                carry = true;
            }
            if (num != alphabet[word3[p3] - 'A']) {
                return;
            }
        }
        while (p1) {
            int num = carry + alphabet[word1[p1] - 'A'];
            if (num >= 10) {
                num %= 10;
                carry = true;
            }
            if (num != alphabet[word3[p3] - 'A']) {
                return;
            }
        }
        ans = true;
        return;
    }
    for (int i = 0; i < 10; i++) {
        alphabet[cnt] = i;
        backtracking(cnt + 1);
        if (ans) {
            return;
        }
        alphabet[cnt] = -1;
    }
}

int main() {
    // 입력
    cin >> word1 >> word2 >> word3;
    n = word3.length();

    if (word1.length() < word2.length()) {
        swap(word1, word2);
    }

    // 연산 & 출력
    backtracking(0);

    if (ans) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}