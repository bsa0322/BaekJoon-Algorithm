#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, x;
    string str;
    bool flag = false;
    cin >> n;
    while (n--) {
        cin >> x;
        if (!flag) {
            cout << x << '\n';
        }
        while (x--) {
            cin >> str;
            if (!flag) {
                cout << str << '\n';
            }
        }
        flag = true;
    }
    return 0;
}