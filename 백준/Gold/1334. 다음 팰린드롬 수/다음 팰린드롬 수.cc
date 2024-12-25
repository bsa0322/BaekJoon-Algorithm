#include <iostream>

using namespace std;

bool checkPlus(int idx, string &input, int &n) {
    // 이전, 이후가 자릿수 벗어나는 경우
    if (idx < 0) {
        return true;
    }
    if (input[idx] == input[n - idx - 1]) {
        // 이전 자릿수의 팰린드롬 수가 앞에 있는 게 더 작다면 현재 자릿수의 수를 1 증가해야 함
        return checkPlus(idx - 1, input, n);
    }
    return input[idx] <= input[n - idx - 1];
}

/**
 * 가운데 인덱스부터 1 증가해서 다음 팰린드롬 수 찾기
 * @param {string} input
 * @return {string} input 보다 큰 팰린드롬 수 중에서 가장 작은 수
 */
string getNextPalindrome(string &input) {
    string ans = input;
    int n = input.length();
    int mid_idx = n / 2 - (n % 2 == 0); // 가운데 인덱스
    bool flag = false;
    bool cache = false;
    for (int i = mid_idx; i >= 0; i--) {
        int curr_num = input[i] - '0';
        if (cache || (!flag && checkPlus(i, input, n))) {
            curr_num++;
        }
        if (curr_num < 10) {
            // 그 다음 수가 있다면
            cache = false;
            ans[i] = ans[n - i - 1] = curr_num + '0';
        } else {
            cache = true;
            ans[i] = ans[n - i - 1] = '0';
        }
        flag = true;
    }
    if (cache) {
        ans = '1' + ans;
        ans[n] = '1';
    }
    return ans;
}

int main() {
    string input;
    cin >> input;
    cout << getNextPalindrome(input);
    return 0;
}