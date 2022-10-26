//
// Created by cse_asus on 2022-10-06.
//

#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e4;

int getMin(string w, int k) {
    int left = 0, right = 0, ans = INF;
    vector<int> alpha(26, 0);
    alpha[w[0] - 'a']++;
    while (left <= right && right < w.length()) {
        if (alpha[w[right] - 'a'] == k) {
            ans = min(ans, right - left + 1);
            alpha[w[left] - 'a']--;
            left++;
        } else if (alpha[w[right] - 'a'] < k) {
            right++;
            if (right == w.length()) {
                break;
            }
            alpha[w[right] - 'a']++;
        }
    }
    return ans;
}

/**
 * 일단 둘 다, 왼쪽에서 시작
 * 최대 k인 첫번째 찾으면 left, right 둘 다 옮김
 * 아직 k가 안되면 right 포인터 이동
 * k이면서 왼쪽 오른쪽 같다면 정답 갱신
 *
 */
/**
 * 반례
 * 1
superaauktornkao
2
 지금 문자열에 포함된 개수보다 아직 K만큼이 남았다면 오른쪽으로 포인터 이동
 이때 기준은 left문자

 해결했는데도 5%에서 틀렸습니다..

 */
int getMax(vector<int> &default_alpha, string w, int k) {
    int left = 0, right = 0, ans = 0;
    vector<int> alpha(26, 0); //부분 문자열에 속한 알파벳 개수
    alpha[w[0] - 'a']++;
    default_alpha[w[0] - 'a']--;
    while (left <= right && right < w.length()) {
//        cout << w[left] << ' ' << w[right] << ' ' << ans << '\n';
        if (alpha[w[left] - 'a'] == k && w[left] == w[right]) {
            ans = max(ans, right - left + 1);
            right++;
            if (right == w.length()) {
                break;
            }
            alpha[w[right] - 'a']++;
            default_alpha[w[right] - 'a']--;
            alpha[w[left++] - 'a']--;
        } else if (default_alpha[w[left] - 'a'] > 0 && k - alpha[w[left] - 'a'] > 0 &&
                   k - alpha[w[left] - 'a'] <= default_alpha[w[left] - 'a']) {
            right++;
            if (right == w.length()) {
                break;
            }
            alpha[w[right] - 'a']++;
            default_alpha[w[right] - 'a']--;
        } else if (alpha[w[left] - 'a'] > k) {
            alpha[w[left++] - 'a']--;
        } else {
            right++;
            if (right == w.length()) {
                break;
            }
            alpha[w[right] - 'a']++;
            default_alpha[w[right] - 'a']--;
            alpha[w[left++] - 'a']--;
        }
    }
    return ans;
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
        vector<int> default_alpha(26, 0);
        for (int i = 0; i < w.length(); i++) {
            default_alpha[w[i] - 'a']++;
        }
        int ans1 = getMin(w, k);
        int ans2 = getMax(default_alpha, w, k);

        if (ans1 == INF) {
            cout << "-1\n";
        } else {
            cout << ans1 << ' ' << ans2 << '\n';
        }

    }
    return 0;
}