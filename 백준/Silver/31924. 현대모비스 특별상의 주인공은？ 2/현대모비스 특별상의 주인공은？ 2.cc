#include <iostream>
#include <vector>

using namespace std;
const string MOBIS = "MOBIS";

int cntMobis(int &r, int &c, vector<string> &board, int &n) {
    int dr[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int dc[8] = {0, 0, -1, 1, -1, 1, -1, 1};

    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        bool flag = true;
        int cr = r, cc = c;
        for (int j = 0; j < 5; j++) {
            if (cr < 0 || cr >= n || cc < 0 || cc >= n || MOBIS[j] != board[cr][cc]) {
                flag = false;
                break;
            }
            cr += dr[i];
            cc += dc[i];
        }
        if (flag) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int n;

    cin >> n;
    vector<string> board(n);
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans += cntMobis(i, j, board, n);
        }
    }
    cout << ans;
    return 0;
}