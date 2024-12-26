#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<string> name = {"Yakk", "Doh", "Seh", "Ghar", "Bang", "Sheesh"};
    vector<string> double_name = {"Habb Yakk", "Dobara", "Dousa", "Dorgy", "Dabash", "Dosh"};
    string five_six = "Sheesh Beesh";

    int t, a, b;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> a >> b;
        a -= 1;
        b -= 1;

        cout << "Case " << i << ": ";
        if (a == b) {
            cout << double_name[a];
        } else {
            if (a < b) {
                swap(a, b);
            }
            if (a == 5 && b == 4) {
                cout << five_six;
            } else {
                cout << name[a] << ' ' << name[b];
            }
        }
        cout << '\n';
    }
    return 0;
}