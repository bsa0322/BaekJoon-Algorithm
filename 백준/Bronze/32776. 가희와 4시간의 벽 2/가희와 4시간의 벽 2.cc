#include <iostream>

using namespace std;

int main() {
    int s, ma, f, mb;
    cin >> s >> ma >> f >> mb;
    if (s <= (ma + f + mb) || s <= 240) {
        cout << "high speed rail";
    } else {
        cout << "flight";
    }
    return 0;
}