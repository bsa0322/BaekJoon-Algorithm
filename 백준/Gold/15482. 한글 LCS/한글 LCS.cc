#include <iostream>
#include <vector>

using namespace std;
const int KOREAN_BYTE = 3;

int lcs(string &str1, string &str2) {
    int str1_len = str1.length();
    int str2_len = str2.length();
    vector<vector<int>> dp(str1_len + KOREAN_BYTE, vector<int>(str2_len + KOREAN_BYTE, 0));
    for (int i = KOREAN_BYTE; i <= str1_len; i += KOREAN_BYTE) {
        for (int j = KOREAN_BYTE; j <= str2_len; j += KOREAN_BYTE) {
            dp[i][j] = max(dp[i - KOREAN_BYTE][j], dp[i][j - KOREAN_BYTE]);
            if (str1.substr(i - KOREAN_BYTE, KOREAN_BYTE) == str2.substr(j - KOREAN_BYTE, KOREAN_BYTE)) {
                dp[i][j] = max(dp[i][j], dp[i - KOREAN_BYTE][j - KOREAN_BYTE] + 1);
            }
        }
    }
    return dp[str1_len][str2_len];
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;

    cout << lcs(str1, str2);
    return 0;
}