#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, r, g, b;
    cin >> n >> m;
    vector<int> intensity_base = {0, 510000, 1020000, 1530000, 2040000};
    vector<char> intensity_change = {'#', 'o', '+', '-', '.'};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> r >> g >> b;
            int intensity = 2126 * r + 7152 * g + 722 * b;
            for (int k = 4; k >= 0; k--) {
                if (intensity_base[k] <= intensity) {
                    cout << intensity_change[k];
                    break;
                }
            }
        }
        cout << '\n';
    }
    return 0;
}