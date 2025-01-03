#include <iostream>
#include <cmath>

using namespace std;
typedef pair<string, string> ps;

string deleteFirstZero(string &str) {
    int zero_cnt = 0;
    for (auto c: str) {
        if (c != '0') {
            break;
        }
        zero_cnt++;
    }
    return str.substr(zero_cnt, str.length());
}

string getMinusCnt(string &a, string &b, int &last_diff) {
    int a_len = a.length(), b_len = b.length();
    if (a_len < last_diff) {
        return "-1";
    }
    string ans = a.substr(a_len - last_diff + 1, a_len);
    int cache = 0;
    for (int i = 0;; i++) {
        int a_num = cache;
        int b_num = 0;
        int a_idx = a_len - last_diff - i;
        int b_idx = b_len - i - 1;
        bool flag = false;
        if (a_idx >= 0 && a_idx < a_len) {
            flag = true;
            a_num += (a[a_idx] - '0');
        }
        if (b_idx >= 0 && b_idx < b_len) {
            flag = true;
            b_num = b[b_idx] - '0';
        }
        if (!flag) {
            break;
        }
        int diff = a_num - b_num;
        if (diff < 0) {
            int curr_cache = ceil(double(abs(diff)) / 10);
            cache = -curr_cache;
            diff += (curr_cache * 10);
        } else {
            cache = 0;
        }
        string diff_str = "";
        diff_str += (diff + '0');
        ans = diff_str + ans;
    }
    if (cache < 0) {
        return "-1";
    }
    return deleteFirstZero(ans);
}

ps division(string a, string b) {
    if (a.length() < b.length() || (a.length() == b.length() && a < b)) {
        return {"0", a};
    }
    string ans = "";
    int start = a.length() - b.length() + 1;
    for (int i = start; i >= 1; i--) {
        // i: 시작 위치
        int cnt = 0;
        while (true) {
            string next = getMinusCnt(a, b, i);
            if (next == "-1") {
                break;
            }
            a = next;
            cnt++;
        }
        ans += (cnt + '0');
    }
    return {deleteFirstZero(ans), (a == "" ? "0" : a)};
}

int main() {
    int n;
    string a, b; // a: 분자, b: 분모
    cin >> n;
    while (n--) {
        cin >> a >> b;
        ps result = division(a, b);
        cout << result.first << '\n' << result.second << "\n\n";
    }
    return 0;
}