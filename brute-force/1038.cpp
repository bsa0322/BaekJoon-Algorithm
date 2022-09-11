//
// Created by BaeSuA on 2022-09-10.
//

#include <iostream>
#include <vector>

using namespace std;
const int MAX_SIZE = 10;

vector<int> num(MAX_SIZE);
int ans_cnt = -1; //감소하는 수 개수

void minusNum(int cnt, int &digit, int &n) {
    if (ans_cnt == n) {
        return;
    }
    if (cnt == digit) {
        ans_cnt++;
        return;
    }
    for (int i = 0; i <= 9; i++) {
        if (cnt == 0 || num[cnt - 1] > i) {
            num[cnt] = i;
            minusNum(cnt + 1, digit, n);
            if (ans_cnt == n) {
                return;
            }
            num[cnt] = 0;
        }
    }
}

int findMinus(int n) {
    for (int i = 1; i <= 10; i++) {
        minusNum(0, i, n);
        if (ans_cnt == n) {
            return i;
        }
    }
    return -1;
}

/**
 * 영화감독 숀과 비슷한 문제.
 * 그냥 감소하는 수 계속 카운트하면서 n번째 찾는 문제
 */

int main() {
    int n;

    // 입력
    cin >> n;

    // 연산 & 출력
    int leng = findMinus(n);

    if (leng == -1) {
        cout << -1;
        return 0;
    }

    for (int i = 0; i < leng; i++) {
        cout << num[i];
    }
    return 0;
}