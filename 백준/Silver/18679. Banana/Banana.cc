#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, t, k;
    string english, temp, minionese;
    map<string, string> dictionary;
    cin >> n;
    while (n--) {
        cin >> english >> temp >> minionese;
        dictionary[english] = minionese;
    }
    cin >> t;
    while (t--) {
        cin >> k;
        while (k--) {
            cin >> english;
            cout << dictionary[english] << ' ';
        }
        cout << '\n';
    }
    return 0;
}