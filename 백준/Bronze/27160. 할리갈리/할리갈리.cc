#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, cnt;
    string fruit;
    map<string, int> fruit_cnt;
    bool ans = false;

    cin >> n;
    while (n--) {
        cin >> fruit >> cnt;
        fruit_cnt[fruit] += cnt;
    }

    for (auto f_info: fruit_cnt) {
        if (f_info.second == 5) {
            ans = true;
            break;
        }
    }

    cout << (ans ? "YES" : "NO");
    return 0;
}