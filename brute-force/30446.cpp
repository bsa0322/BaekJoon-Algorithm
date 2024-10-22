#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
const int LENGTH = 10;

/**
 * 회문수: https://www.acmicpc.net/problem/30446
 * 규칙찾기 or 브루트 포스
 */

int bruteForce(string &n) {
    int answer = 0;
    long long n_int = stoll(n);

    // n의 절반 길이까지의 수로 팰린드롬 수 만들어서 n 이하인지 탐색
    // ex) n = 99999, 999까지 탐색
    for (int i = 1; i <= stoll(n.substr(0, n.length() / 2 + 1)); i++) {
        string new_n = to_string(i);
        string new_n_rev = new_n;
        reverse(new_n_rev.begin(), new_n_rev.end());

        string p1 = new_n + new_n_rev.substr(1, new_n_rev.length()); // 홀수 팰린드롬
        string p2 = new_n + new_n_rev; // 짝수 팰린드롬
        if (stoll(p1) <= n_int) {
            answer++;
        }
        if (stoll(p2) <= n_int) {
            answer++;
        }
    }
    return answer;
}

int calcByRule(string &n) {
    vector<int> cnt(LENGTH + 1, 0); // 각 자릿수마다 처음 값이 고정일 때의 회문수 개수 저장
    cnt[0] = cnt[1] = cnt[2] = 1;
    for (int i = 3; i <= LENGTH; i++) {
        cnt[i] = cnt[i - 2] * 10;
    }

    int len = n.length();
    ll ans = 0;

    // 그 전 자릿수까진 다 더하기
    for (int i = 1; i < len; i++) {
        ans += 9 * cnt[i]; // 처음 시작이 1 ~ 9 까지 가능하므로 9 곱해서 더함
    }
    // 현재 자릿수에서 처음 수로 시작하는 경우의 회문수 개수 구하기
    for (int i = 0; i < (len + 1) / 2; i++) {
        int first = n[i] - '0';
        if (i == 0) {
            ans += (first - 1) * cnt[len - i * 2];
        } else {
            ans += first * cnt[len - i * 2];
        }
    }

    // 마지막에 현재 자릿수의 절반으로 만든 팰린드롬이 주어진 수보다 작다면
    string rev_n = n.substr(0, (n.length() + 1) / 2);
    string new_n = rev_n;
    reverse(rev_n.begin(), rev_n.end());
    // 짝 or 홀에 따라 나뉨
    if (n.length() % 2 == 0) {
        new_n += rev_n;
    } else {
        new_n += rev_n.substr(1, rev_n.length());
    }

    if (stoll(new_n) <= stoll(n)) {
        return ans + 1;
    }
    return ans;
}

int main() {
    string n;
    cin >> n;
//    cout << bruteForce(n);
    cout << calcByRule(n);

    return 0;
}