#include <iostream>
#include <deque>

using namespace std;
typedef pair<int, int> pi;

// https://www.acmicpc.net/problem/2346

int main() {
    int n, t;
    deque<pi> dq; // first: 풍선 안에 있는 종이, second: 풍선 번호

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        dq.emplace_back(t, i + 1);
    }

    while (!dq.empty()) {
        int interval = dq.front().first;
        int num = dq.front().second;
        dq.pop_front();

        cout << num << ' ';

        if (interval > 0) {
            while (--interval) { // 오른쪽으로 이동 -> 원형이니까 뒤로 보내기
                dq.emplace_back(dq.front().first, dq.front().second);
                dq.pop_front();
            }
        } else {
            while (-(interval++)) { // 왼쪽으로 이동 -> 뒤에 있는 걸 앞으로 보내기
                dq.emplace_front(dq.back().first, dq.back().second);
                dq.pop_back();
            }
        }
    }

    return 0;
}