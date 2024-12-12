#include <iostream>
#include <vector>

using namespace std;
const int INF = 500;

/**
 * 가능한 연속하는 2 쌍의 차이를 기준으로 맞췄을 때의 변환 횟수 구해서 최솟값 구하기
 */
int getCnt(int &n, vector<int> &num) {
    int ans = INF;
    for (int i = 1; i < n; i++) {
        int diff = num[i] - num[i - 1];
        int cnt = 0;
        // 왼쪽 방향 변경
        int last_num = num[i - 1];
        for (int j = i - 2; j >= 0; j--) {
            if (last_num - num[j] != diff) {
                cnt++;
            }
            last_num -= diff;
        }
        // 오른쪽 방향 변경
        last_num = num[i];
        for (int j = i + 1; j < n; j++) {
            if (num[j] - last_num != diff) {
                cnt++;
            }
            last_num += diff;
        }
        ans = min(ans, cnt);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    cout << getCnt(n, num);
    return 0;
}