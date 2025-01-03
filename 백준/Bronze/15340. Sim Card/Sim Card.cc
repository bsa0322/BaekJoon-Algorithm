#include <iostream>
#include <vector>

using namespace std;
const int INF = 2e9;

typedef struct Bill {
    int c, d;
} bill;

int main() {
    bill student; // call , data
    vector<bill> phone = {{30, 40},
                          {35, 30},
                          {40, 20}};

    while (cin >> student.c >> student.d) {
        if (student.c == 0 && student.d == 0) {
            break;
        }

        // 가장 싼 요금 찾기
        int ans = INF;
        for (auto p: phone) {
            int curr_bill = student.c * p.c + student.d * p.d;
            ans = min(ans, curr_bill);
        }
        cout << ans << '\n';
    }
    return 0;
}