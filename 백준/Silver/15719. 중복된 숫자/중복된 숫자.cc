#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;

    cin >> n;
    vector<int> num(n);
    vector<bool> check(n, false);

    for (int i = 0; i < n; i++) {
        cin >> num[i];
        if (check[num[i]]) {
            m = num[i];
        }
        check[num[i]] = true;
    }

    cout << m;
    return 0;
}