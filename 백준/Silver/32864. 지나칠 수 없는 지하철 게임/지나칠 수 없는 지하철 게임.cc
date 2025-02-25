#include <iostream>
#include <vector>

using namespace std;

int getBestPos(int start, int &n, vector<int> &subway, vector<int> &cnt) {
    for (int i = start; i < n - 1; i++) {
        if (subway[i + 1] == 1) {
            if (cnt[i + 1] % 2 == 0) {
                return i + 1;
            }
            return i;
        }
    }
    return n - 1;
}

int main() {
    int n, prev = 0, st_idx = 0;

    cin >> n;
    vector<int> subway(n, 0); // 0: 일반, 1: 환승
    vector<int> cnt(n, 0); // 연속 1 카운트 세기
    for (int i = 0; i < n; i++) {
        cin >> subway[i];
        cnt[i] = subway[i];
        if (subway[i] && prev == 1) {
            cnt[st_idx]++;
        } else if (subway[i] && prev == 0) {
            st_idx = i;
        } else if (!subway[i]) {
            st_idx = 0;
        }
        prev = subway[i];
    }

    // 게임 진행
    bool turn = true; // 세훈
    int pos = 0;
    while (true) {
        pos++;
        if (pos == n - 1) {
            break;
        }
        if (subway[pos] == 1) {
            turn = !turn;
            continue;
        }
        pos = getBestPos(pos, n, subway, cnt);
        if (pos == n - 1) {
            break;
        }
        turn = !turn;
    }
    if (turn) {
        cout << "mnx";
    } else {
        cout << "alsdkffhgk";
    }
    return 0;
}