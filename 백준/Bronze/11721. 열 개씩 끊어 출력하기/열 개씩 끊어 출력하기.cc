#include <iostream>

using namespace std;

int main() {
    string str;
    cin >> str;
    for (int i = 0; i < str.length();) {
        cout << str[i++];
        if (i % 10 == 0) {
            cout << '\n';
        }
    }
    return 0;
}