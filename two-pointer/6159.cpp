//
// Created by cse_asus on 2022-10-20.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int s, n;

    cin >> n >> s;
    vector<int> cow(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> cow[i];
    }
    sort(cow.begin(), cow.end());
    int ans = 0;

    int left = 0, right = n - 1;
    while (left < right) {
        int sum = cow[left] + cow[right];
        if (sum <= s) {
            //sum <= s라는건 left~right사이에 있는 값과 left가 짝지어도 s 이하라는 소리!!
            //따라서 해당 개수(right-left-1)과 left,right 쌍 1개를 더함 => right-left-1+1=right-left
            ans += right-left;
            left++;
        } else {
            right--;
        }
    }
    cout << ans;
    return 0;
}