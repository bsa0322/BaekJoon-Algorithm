#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool isExplosion(stack<char> &st, int &explode_len, string &explode) {
    for (int i = explode_len - 1; i >= 0; i--) {
        if (st.empty() || st.top() != explode[i]) {
            // 스택 다시 채우기
            for (int j = i + 1; j < explode_len; j++) {
                st.push(explode[j]);
            }
            return false;
        }
        st.pop();
    }
    return true;
}

string getAfterExplosion(string &input, string &explode) {
    stack<char> st;
    int explode_len = explode.length();
    for (int i = 0; i < input.length(); i++) {
        st.push(input[i]);
        if (explode[explode_len - 1] == input[i]) {
            isExplosion(st, explode_len, explode);
        }
    }

    // 폭발 후 남은 문자열
    string result = "";
    result.assign(st.size(), ' ');
    int idx = st.size() - 1;
    while (!st.empty()) {
        result[idx--] = st.top();
        st.pop();
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string input, explode;

    cin >> input >> explode;

    string result = getAfterExplosion(input, explode);

    cout << (result.length() == 0 ? "FRULA" : result);
    return 0;
}