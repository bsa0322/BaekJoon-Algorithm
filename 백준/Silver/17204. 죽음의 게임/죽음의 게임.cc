#include <iostream>
#include <vector>

using namespace std;

int getMinimumCnt(int &n, int &k, vector<int> &pointer) {
    vector<bool> check(n, false);
    int next_pointer = 0;
    int curr_cnt = 0;
    while (true) {
        if (next_pointer == k) {
            break;
        }
        if (check[next_pointer]) {
            return -1;
        }
        check[next_pointer] = true;
        next_pointer = pointer[next_pointer];
        curr_cnt++;
    }
    return curr_cnt;
}

int main() {
    int n, k; // n: 게임 참여 사람 수, k: 보성이 번호
    cin >> n >> k;
    vector<int> pointer(n);

    for (int i = 0; i < n; i++) {
        cin >> pointer[i];
    }

    cout << getMinimumCnt(n, k, pointer);
    return 0;
}