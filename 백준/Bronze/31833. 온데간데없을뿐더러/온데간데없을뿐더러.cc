#include <iostream>

using namespace std;

int main() {
    int n, num;
    string x = "", y = "";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        x += to_string(num);
    }
    for (int i = 0; i < n; i++) {
        cin >> num;
        y += to_string(num);
    }
    if (stoll(x) < stoll(y)) {
        cout << x;
    } else {
        cout << y;
    }
    return 0;
}