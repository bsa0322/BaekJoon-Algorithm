//
// Created by cse_asus on 2022-10-11.
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
typedef pair<int, char> ic;

/**
 * 첫 시도. 단어 길이 (큰거부터) 정렬해서, 순서대로 알파벳 부여. 차례로 검사하면서 이미 부여된 알파벳이라면 넘어감.
 * -> 문제점: 같은 자릿수 내에서 먼저 부여하면 좋은 알파벳이 있음 (예를들어 AB BB 일 경우, B에 9를 부여하는 게 A에 9를 부여하는 것보다 좋음)
 * -> 그럼 자릿수를 더해서 자릿수가 가장 높은 알파벳부터 수를 부여하자.
 * -> 이때, 자릿수 더하기는 꼭 1, 10, 100.. 으로 더해야 함!! -> 일의 자리가 10개 있어야 10의 자리 몫을 하는거니까
 *          (1,2,3 으로 더했을 시 반례)
 *                  AB
 *                  CB
 *
 */

int main() {
    int n;

    cin >> n;
    vector<string> word(n);
    vector<ic> alpha(26, {0, ' '});
    vector<int> num(26, 0);
    for (int i = 0; i < n; i++) {
        cin >> word[i];
        int p = 1;
        for (int j = word[i].length() - 1; j >= 0; j--) {
            alpha[word[i][j] - 'A'].first += p;
            alpha[word[i][j] - 'A'].second = word[i][j];
            p *= 10;
        }
    }

    sort(alpha.begin(), alpha.end(), greater<>());

    int cnt = 9;
    for (int i = 0; i < 10; i++) {
        num[alpha[i].second - 'A'] = cnt--;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        string s = "";
        for (int j = 0; j < word[i].length(); j++) {
            s += to_string(num[word[i][j] - 'A']);
        }
        ans += stoi(s);
    }

    cout << ans;
    return 0;
}