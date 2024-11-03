#include <iostream>
#include <vector>
#include <map>

using namespace std;
const string RAINBOW_DANCE = "ChongChong";

int main() {
    int n, ans = 1;
    string str1, str2;

    cin >> n;
    map<string, bool> check;
    check[RAINBOW_DANCE] = true;
    for (int i = 0; i < n; i++) {
        cin >> str1 >> str2;
        if (check[str1] && !check[str2]) {
            check[str2] = true;
            ans++;
        } else if (check[str2] && !check[str1]) {
            check[str1] = true;
            ans++;
        }
    }
    cout << ans;
    return 0;
}