#include <iostream>
#include <vector>

using namespace std;
const int ALPHA = 26;

char maxCntAlpha(string &str) {
    vector<int> cnt(ALPHA, 0);
    for (auto c: str) {
        int idx = c - 'A';
        if (c >= 'a') {
            idx = c - 'a';
        }
        cnt[idx]++;
    }
    bool flag = false; // 가장 많이 사용된 알파벳 여러 개인지 확인
    int max_cnt = 0;
    char max_alpha = '\0';
    for (int i = 0; i < ALPHA; i++) {
        if (cnt[i] > max_cnt) {
            flag = false;
            max_cnt = cnt[i];
            max_alpha = i + 'A';
        } else if (cnt[i] == max_cnt) {
            flag = true;
        }
    }
    return (flag ? '?' : max_alpha);
}

int main() {
    string str;
    cin >> str;
    cout << maxCntAlpha(str);
    return 0;
}