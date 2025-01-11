#include <iostream>

using namespace std;

int main() {
    int k;
    cin >> k;

    string first = "AKARAKA";
    string routine = "RAKA";
    string ans = first;
    for (int i = 1; i < k; i++) {
        ans += routine;
    }
    cout << ans;
    return 0;
}