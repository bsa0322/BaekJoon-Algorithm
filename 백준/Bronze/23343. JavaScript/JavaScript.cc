#include <iostream>

using namespace std;

bool isRealNum(string &str) {
    for (auto c: str) {
        if ((c < '0' || c > '9') && c != '.') {
            return false;
        }
    }
    return true;
}

int main() {
    string a, b;
    cin >> a >> b;

    if (!isRealNum(a) || !isRealNum(b)) {
        cout << "NaN";
    } else {
        double da = stod(a);
        double db = stod(b);
        cout << (da - db);
    }
    return 0;
}