//
// Created by BaeSuA on 2022-11-09.
//

#include <iostream>
#include <vector>

using namespace std;

int n, s, ans;
vector<int> num;

void f(int c, int cnt, int sum) {
    if (cnt == n) {
        if (c != 0 && sum == s) {
            ans++;
        }
        return;
    }
    f(c + 1, cnt + 1, sum + num[cnt]);
    f(c, cnt + 1, sum);
}

/**
 * 처음엔 부분수열이라 그래서, 연속해야하는 줄 알았다..
 * 그래서 누적합으로 부분수열합 경우의 수 다 구해서 풀었는데 틀림
 * 그래서 질문검색 보니까 연속하지 않아도 괜찮은 거였음..!
 * 다시 재귀로 풀이..
 */

int main() {
    cin >> n >> s;
    num.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    f(0, 0, 0);
    cout << ans;
    return 0;
}