#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getCntSumX(int &n, int &x, vector<int> &num) {
    int left = 0, right = n - 1, ans = 0;
    while (left < right) {
        int sum = num[left] + num[right];
        if (sum == x) {
            ans++;
        }
        if (sum < x) {
            left++;
        } else {
            // sum 이 같거나 더 크다면
            right--;
        }
    }
    return ans;
}

/**
 * 서로 다른 두 수이므로 투 포인터 진행할 때 while문 조건에 등호 들어가면 안됨 !!
 */
int main() {
    int n, x;

    // 수열 크기 입력
    cin >> n;
    // 수열 숫자 입력
    vector<int> num(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    // 합인지 확인하는 수 입력
    cin >> x;

    // 정렬
    sort(num.begin(), num.end());

    // num[i] + num[j] = x 만족하는 i, j 쌍 수
    cout << getCntSumX(n, x, num);
    return 0;
}