//
// Created by BaeSuA on 2022-09-04.
//

#include <iostream>
#include <stack>

using namespace std;

int changeStable(string s) {
    stack<char> st;
    int cnt = 0;

    // 스택에 넣으면서 닫는 괄호에 대한 연산
    // 스택이 비었는데 닫는 괄호가 나온다면 여는 괄호로 바꿈
    for (auto c: s) {
        if (c == '{') {
            st.push(c);
            continue;
        }
        if (st.empty()) {
            cnt++;
            st.push('{');
        } else {
            st.pop();
        }
    }
    // 마지막 여는 괄호에 대해서 바꿔야 할 개수 카운트
    // 여는 괄호 2개에서 하나를 닫는 괄호로 바꿈
    // 항상 길이 짝수이므로 두 개씩 pop해도 괜찮음
    while (!st.empty()) {
        st.pop();
        st.pop();
        cnt++;
    }

    return cnt;
}

int main() {
    string s;
    int test_case = 0;

    // 입력 & 연산
    while (cin >> s && ++test_case) {
        if (s[0] == '-') { // 입력 마지막
            break;
        }

        // 출력
        cout << test_case << ". " << changeStable(s) << '\n';
    }
    return 0;
}