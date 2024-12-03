#include <iostream>

using namespace std;

int getMinimumPack(int &n) {
    string curr = "10";
    for (int i = 1;; i++) {
        int curr_num = stoi(curr);
        if (n <= curr_num) {
            return i;
        }
        curr = "1" + curr;
    }
}

/**
 * 최소 스티커 팩의 개수 -> 0 ~ 9 중 필요한 최대 개수
 * 0 ~ 10  : 1개
 * 11 ~ 110: 2개
 * 111 ~ 1110: 3개
 * ...
 */
int main() {
    int n;
    cin >> n;

    cout << getMinimumPack(n);
    return 0;
}