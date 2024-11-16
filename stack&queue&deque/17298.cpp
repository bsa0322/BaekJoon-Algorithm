#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/**
 * [오큰수]
 *
 * 자기보다 오른쪽에 있는 큰 수 중 가장 왼쪽에 있는 수
 *
 * => 거꾸로 순회하면서 자기보다 작으면 stack에 넣고, 현재 stack의 top에 있는 게 오큰수임
 */
int main() {
    int n;
    stack<int> st;

    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    // 오큰수 저장
    vector<int> ans(n, -1);

    // 가장 마지막 수 넣기
    st.push(num[n - 1]);

    // 오큰수 확인
    for (int i = n - 2; i >= 0; i--) {
        while (!st.empty() && st.top() <= num[i]) {
            st.pop();
        }
        if (!st.empty()) {
            ans[i] = st.top();
        }
        st.push(num[i]);
    }

    // 출력
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}