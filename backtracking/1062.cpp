#include <iostream>
#include <vector>
#include <set>

using namespace std;

int k, n;
vector<string> words;
int check;
vector<int> words_check;
int answer = 0;
vector<int> alphas;

void backtracking(int cnt, int t) {
    if (cnt == k) {
        int temp_ans = 0;
        for (int i = 0; i < n; i++) {
            if ((words_check[i] & check) == words_check[i]) {
                temp_ans++;
            }
        }
        answer = max(answer, temp_ans);
        return;
    }

    for (int i = t; i < 21; i++) {
        if (!(check & (1 << alphas[i]))) {
            check |= (1 << alphas[i]);
            backtracking(cnt + 1, i + 1);
            check &= ~(1 << alphas[i]);
        }
    }
}

/**
 * https://www.acmicpc.net/problem/1062
 *
 * a, c, i, n, t 5개는 무조건 가르쳐야 함
 * @return
 */

int main() {
    cin >> n >> k;
    if (k < 5) {
        cout << 0;
        return 0;
    }

    words.assign(n, "");
    words_check.assign(n, 0);
    set<char> basic = {'a', 'c', 'i', 'n', 't'};

    for (int i = 0; i < n; i++) {
        cin >> words[i];
        for (char j: basic) {
            words_check[i] |= (1 << (j - 'a'));
        }
        bool temp = true;
        for (int j = 4; j < words[i].length() - 4; j++) {
            if (basic.find((words[i][j])) == basic.end()) {
                temp = false;
            }
            words_check[i] |= (1 << (words[i][j] - 'a'));
        }
        if (temp) {
            answer++;
        }
    }

    for (char i: basic) {
        check |= (1 << (i - 'a'));
    }

    for (int i = 0; i < 26; i++) {
        if (basic.find(('a' + i)) == basic.end()) {
            alphas.push_back(i);
        }
    }

    if (k > 5) {
        backtracking(5, 0);
    }

    cout << answer;

    return 0;
}