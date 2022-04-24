#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    string s;
    vector<int> check(26, 0);

    cin >> n >> s;
    for (int i = 0; i < s.length(); i++)
        check[s[i] - 'A']++;

    int ans = 0;
    for (int i = 1; i < n; i++) {
        cin >> s;
        vector<int> check2 = check;
        for (int i = 0; i < s.length(); i++) //비교하려는 문자열의 문자는 기존 문자열 정보에서 빼주기
            check2[s[i] - 'A']--;
        int cnt = 0; //하나 바꾸는 경우의 개수 세기
        bool first1 = true, first2 = true; //처음 1과 -1에 대한 처리
        for (int i = 0; i < 26; i++) {
            if (check2[i] == 1 && first1) { //하나를 더해야 기존 문자와 같아지는 경우
                first1 = false;
                if (!first2) //하나를 빼는 게 먼저 있었다면 한 문자를 다른 문자로 대체하는 경우이므로 cnt 1만 증가
                    cnt++;
            } else if (check2[i] == -1 && first2) { //하나를 빼야 기존 문자와 같아지는 경우
                first2 = false;
                if (!first1)
                    cnt++;
            } else
                cnt += abs(check2[i]);
        }
        if (first1 != first2) //1과 -1 둘 중 하나만 나왔다면 못 세줬던 바꾸는 횟수 세기
            cnt++;
        if (cnt <= 1) //하나 바꾸는 경우가 하나 이하여야 함
            ans++;
    }

    cout << ans;

    return 0;
}