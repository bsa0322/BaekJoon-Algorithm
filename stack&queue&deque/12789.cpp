#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> students(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> students[i];
    }

    int curr_num = 1, curr_idx = 0;
    stack<int> st;
    while (true) {
        while (!st.empty() && st.top() == curr_num) {
            st.pop();
            curr_num++;
        }
        if (curr_idx == n || curr_num == n + 1) {
            break;
        }
        st.push(students[curr_idx++]);
    }

    if (curr_num == n + 1) {
        cout << "Nice";
    } else {
        cout << "Sad";
    }
    return 0;
}