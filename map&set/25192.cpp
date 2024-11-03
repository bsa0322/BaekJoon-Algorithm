#include <iostream>
#include <vector>
#include <map>

using namespace std;
const string NEW_PERSON = "ENTER";

int main() {
    int n, ans = 0;
    string str;

    cin >> n;
    vector<string> chats(n);
    map<string, bool> check;
    for (int i = 0; i < n; i++) {
        cin >> chats[i];
    }
    for (int i = 0; i < n; i++) {
        if (chats[i] == NEW_PERSON) {
            check.clear();
            continue;
        }
        if (!check[chats[i]]) {
            check[chats[i]] = true;
            ans++;
        }
    }
    cout << ans;
    return 0;
}