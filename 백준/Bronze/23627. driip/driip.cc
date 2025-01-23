#include <iostream>
#include <algorithm>

using namespace std;
const string DRIIP = "piird";

int main() {
    string input;
    cin >> input;
    reverse(input.begin(), input.end());
    if (input.substr(0, DRIIP.length()) == DRIIP) {
        cout << "cute";
    } else {
        cout << "not cute";
    }

    return 0;
}