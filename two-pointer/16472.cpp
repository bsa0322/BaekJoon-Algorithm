//
// Created by cse_asus on 2022-10-22.
//

#include <iostream>
#include <vector>

using namespace std;

int solution(int n, string &s) {
    int left = 0;
    int right = 0;
    int ans = 0;
    vector<int> alpha(26, 0);
    int cnt = 1;
    alpha[s[0] - 'a'] = 1;
    while (left <= right && right < s.length()) {
        if (cnt <= n) {
            //cout<<s[left]<<' '<<s[right]<<' '<<cnt<<' '<<right-left+1<<'\n';
            ans = max(ans, right - left + 1);
            right++;
            if (right == s.length()) {
                break;
            }
            if (alpha[s[right] - 'a'] == 0) {
                cnt++;
            }
            alpha[s[right] - 'a']++;
        } else {
            if (alpha[s[left] - 'a'] == 1) {
                cnt--;
            }
            alpha[s[left] - 'a']--;
            left++;
        }
    }
    return ans;
}

int main() {
    int n;
    string s;

    cin >> n >> s;

    cout << solution(n, s);
    return 0;
}