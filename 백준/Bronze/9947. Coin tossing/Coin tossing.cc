#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<string> players(2);
    int n;
    char q, a;
    while (true) {
        vector<int> ans(2);
        cin >> players[0] >> players[1];
        if (players[0] == "#" && players[1] == "#") {
            break;
        }
        cin >> n;
        while (n--) {
            cin >> q >> a;
            ans[(q != a)]++;
        }
        for (int i = 0; i < 2; i++) {
            cout << players[i] << ' ' << ans[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}