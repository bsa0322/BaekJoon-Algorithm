#include <iostream>
#include <vector>

using namespace std;

int main() {
    int c, n;
    cin >> c;
    while (c--) {
        cin >> n;
        int sum = 0;
        vector<int> score(n);
        for (int i = 0; i < n; i++) {
            cin >> score[i];
            sum += score[i];
        }
        double avg = (double) sum / n;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (avg < (double) score[i]) {
                cnt++;
            }
        }
        double ans = (double) cnt / n * 100;

        cout << fixed;
        cout.precision(3);
        cout << ans << "%\n";
    }
    return 0;
}