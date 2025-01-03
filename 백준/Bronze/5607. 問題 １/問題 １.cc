#include <iostream>

using namespace std;

int main() {
    int n, a, b, score_a = 0, score_b = 0;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        int score = a + b;
        if (a > b) {
            score_a += score;
        } else if (a < b) {
            score_b += score;
        } else {
            // 무승부
            score_a += a;
            score_b += b;
        }
    }
    cout << score_a << ' ' << score_b;
    return 0;
}