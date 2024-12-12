#include <iostream>
#include <vector>

using namespace std;
const int INF = 500;

/**
 * 가능한 연속하는 2 쌍의 차이를 기준으로 맞췄을 때의 변환 횟수 구해서 최솟값 구하기
 */
int getCnt(int &n, vector<int> &num) {
    int ans = INF;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int diff_value = num[j] - num[i];
            int diff_idx = j - i;
            if (diff_value % diff_idx != 0) {
                // 사이에 일정한 수로 나눌 수 없으면 넘어가기
                continue;
            }
            int diff = diff_value / diff_idx; // 두 수의 차이 값
            int cnt = 0; // 바꾸는 횟수
            int temp_num = num[i];
            for (int k = i; k >= 0; k--) {
                if (temp_num != num[k]) {
                    cnt++;
                }
                temp_num -= diff;
            }
            temp_num = num[i];
            for (int k = i; k < n; k++) {
                if (temp_num != num[k]) {
                    cnt++;
                }
                temp_num += diff;
            }
            ans = min(ans, cnt);
        }
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
