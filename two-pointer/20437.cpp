//
// Created by cse_asus on 2022-10-06.
//

#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e4;

pair<int, int> getString(string w, int k) {
    int left = 0;
    int right = 0;
    vector<int> alpha(26, 0);
    int ans1 = INF, ans2 = 0;
    alpha[w[right] - 'a']++;
    while (left <= right && right < w.length()) {
        int left_num = w[left] - 'a';
        int right_num = w[right] - 'a';

        if (alpha[right_num] == k) {
            int leng = right - left + 1;
            ans1 = min(ans1, leng);
            if (w[left] == w[right]) {
                ans2 = max(ans2, leng);
            }
            alpha[left_num]--;
            left++;
        } else if (alpha[right_num] < k) {
            right++;
            alpha[w[right] - 'a']++;
        }
    }
    return {ans1, ans2};
}

/**
 * 어떤 문자 정확히 K 개 포함하는 가장 짧은 연속 문자열 길이
 * 어떤 문자 정확히 K 개 포함하고 문자열 첫 번째와 마지막 글자가 해당 문자로 같은 가장 긴 연속 문자열
 *
 * 만족하는 연속 문자열 없으면 -1 출력
 * @return
 */

int main() {
    string w;
    int t, k;

    cin >> t;
    while (t--) {
        cin >> w >> k;
        pair<int, int> ans = getString(w, k);

        if (ans.first == INF) {
            cout << "-1\n";
        } else {
            cout << ans.first << ' ' << ans.second << '\n';
        }

    }
    return 0;
}