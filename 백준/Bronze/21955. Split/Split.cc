#include <iostream>

using namespace std;

int main() {
    string input;
    cin >> input;
    int len = input.length();
    for (int i = 0; i < len / 2; i++) {
        cout << input[i];
    }
    cout << ' ';
    for (int i = len / 2; i < len; i++) {
        cout << input[i];
    }
    return 0;
}