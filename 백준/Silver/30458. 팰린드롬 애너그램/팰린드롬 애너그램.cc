#include <iostream>
#include <vector>

using namespace std;
const int ALPHA = 26;

bool isPossiblePalindrome(vector<int> &cnt) {
    for (int i = 0; i < ALPHA; i++) {
        if (cnt[i] % 2 == 1) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    string str;
    vector<int> cnt(ALPHA, 0);

    cin >> n >> str;
    for (int i = 0; i < n / 2; i++) {
        cnt[str[i] - 'a']++;
    }
    for (int i = (n + 1) / 2; i < n; i++) {
        cnt[str[i] - 'a']++;
    }

    cout << (isPossiblePalindrome(cnt) ? "Yes" : "No");
    return 0;
}