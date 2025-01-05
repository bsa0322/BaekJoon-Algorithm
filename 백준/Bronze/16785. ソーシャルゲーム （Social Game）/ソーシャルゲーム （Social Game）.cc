#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int day = 0, sum = 0;
    while (sum < c) {
        sum += a;
        day++;
        if (day % 7 == 0) {
            sum += b;
        }
    }
    cout << day;
    return 0;
}