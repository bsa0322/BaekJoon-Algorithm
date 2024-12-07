#include <iostream>

using namespace std;

int getMinimumK(int &n, string &str) {
    // 부분 문자열 길이 1 부터 확인해서 가장 작은 K 값 찾기
    for (int i = 1; i <= n; i++) {
        // 시작점을 j로 부분 문자열 만들어서 확인
        bool flag = true;
        for (int j = 0; j < n - i + 1; j++) {
            string sub = str.substr(j, i);
            for (int k = j + 1; k < n - i + 1; k++) {
                string sub_temp = str.substr(k, i);
                if (sub == sub_temp) {
                    flag = false;
                    break;
                }
            }
            if (!flag) {
                break;
            }
        }
        if (flag) {
            return i;
        }
    }
}

int main() {
    int n;
    string str;

    cin >> n >> str;

    cout << getMinimumK(n, str);
    return 0;
}