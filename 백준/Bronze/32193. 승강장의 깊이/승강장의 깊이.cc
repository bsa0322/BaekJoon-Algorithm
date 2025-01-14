#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, a, b, h = 0, s = 0;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        h += a;
        s += b;
        cout << h - s << '\n';
    }
    return 0;
}