//
// Created by BaeSuA on 2022-09-12.
//

// 브루트 포스 풀이 - 재귀함수..

#include <iostream>
#include <vector>

using namespace std;
const int MAX = 1e9;

int n;
int max_ans = -MAX, min_ans = MAX;
vector<int> arr, calc;

int calcArith(int a, int b, int c) {
    switch (c) {
        case 0: //+
            return a + b;
        case 1: //-
            return a - b;
        case 2: //*
            return a * b;
        case 3: // 나누기
            return a / b;
    }
}

void makeExpress(int cnt, int sum) {
    if (cnt == n - 1) {
        max_ans = max(max_ans, sum);
        min_ans = min(min_ans, sum);
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (calc[i]) {
            calc[i]--;
            makeExpress(cnt + 1, calcArith(sum, arr[cnt + 1], i));
            calc[i]++;
        }
    }
}

int main() {
    //입력
    cin >> n;
    arr.assign(n, 0);
    calc.assign(4, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> calc[i];
    }

    //연산
    makeExpress(0, arr[0]);

    //출력
    cout << max_ans << '\n' << min_ans;
    return 0;
}