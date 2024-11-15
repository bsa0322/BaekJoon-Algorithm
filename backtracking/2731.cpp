#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

// 특정 자릿수까지만 배열 곱해서 넘겨주기 (a * b)
vector<int> multipleMat(int &d, vector<int> &a, vector<int> &b) {
    vector<int> result(d, 0);
    int a_size = a.size();

    for (int i = 0; i < b.size(); i++) {
        ll cache = 0;
        for (int j = 0; j < a.size(); j++) {
            if (i + j >= d) {
                break;
            }
            result[i + j] += (a[j] * b[i]) + cache;
            cache = result[i + j] / 10;
            result[i + j] %= 10;
        }
        if (i + a_size < d) {
            result[i + a_size] += (cache % 10);
            if (i + a_size + 1 < d) {
                result[i + a_size + 1] += (cache / 10);
            }
        }
    }

    return result;
}

// 현재 자릿수까지 같은지 비교해서 넘겨주기
bool checkSpecificDigits(int &d, int &d_x, string &s, vector<int> &ans, bool &is_ans) {
    int s_len = s.length();
    vector<int> temp = ans;
    temp.push_back(d_x); // 현재 자릿수에 확인하고 있는 수 넣기

    // 제곱
    vector<int> twice = multipleMat(s_len, temp, temp);

    // 세제곱
    vector<int> triple = multipleMat(s_len, twice, temp);

    // 비교하기 위해 string 형태로 만들기
    string triple_str = "";
    for (int i = 0; i < triple.size(); i++) {
        triple_str += to_string(triple[i]);
    }

    // 아예 같다면 정답
    if (triple_str.substr(0, s_len) == s.substr(0, s_len)) {
        is_ans = true;
    }

    return triple_str.substr(0, d + 1) == s.substr(0, d + 1);
}

// 일의 자리 구하기
int getTens(ll &s) {
    int s_tens = s % 10;
    switch (s_tens) {
        case 1:
            return 1;
        case 3:
            return 7;
        case 7:
            return 3;
        case 9:
            return 9;
    }
}

/**
 * 1. x의 끝 자리 수 구하기
 * 2. 그 다음 자리부터 0 ~ 9 까지 돌면서 해당 자릿수까지 s와 같은지 확인
 *    - 이때, 전체 자릿수가 s와 같다면 여기서 종료
 *
 * 시간 복잡도: T * 10^3
 */
int main() {
    int t;
    ll s;

    cin >> t;
    while (t--) {
        cin >> s;

        bool is_ans = false; // 정답 만족하는지 확인

        vector<int> ans; // 일의 자리부터 저장
        ans.push_back(getTens(s)); // 일의 자리 구해서 넣기

        string s_str = to_string(s);
        // 일의 자리부터 확인하기 위해 뒤집기
        reverse(s_str.begin(), s_str.end());
        for (int i = 1; i < s_str.length(); i++) {
            // 최대 s의 길이까지 확인
            for (int j = 0; j <= 9; j++) {
                // 0 ~ 9 까지 만족하는지 확인
                if (checkSpecificDigits(i, j, s_str, ans, is_ans)) {
                    // 만족하면 넣기
                    ans.push_back(j);
                    break;
                }
            }
            if (is_ans) {
                // 정답 만족했다면 멈추기
                break;
            }
        }

        // 출력
        bool is_first = true;
        for (int i = ans.size() - 1; i >= 0; i--) {
            if (is_first && ans[i] == 0) {
                // 시작이 0이 아니도록 주의 !!
                continue;
            }
            is_first = false;
            cout << ans[i];
        }
        cout << '\n';
    }
    return 0;
}