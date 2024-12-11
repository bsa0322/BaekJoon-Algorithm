#include <iostream>

using namespace std;

int getTicketCnt(int &n) {
    string target = "2023";
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int curr_idx = 0;
        string ticket = to_string(i);
        for (char t: ticket) {
            if (target[curr_idx] == t) {
                curr_idx++;
            }
        }
        if (curr_idx == target.length()) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;

    cout << getTicketCnt(n);
    return 0;
}