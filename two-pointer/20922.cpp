#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;

    //입력
    cin >> n >> k;
    vector<int> num(n, 0);
    vector<int> number(100001, 0);
    for (int i = 0; i < n; i++)
        cin >> num[i];

    int l = 0, r = 0;
    int ans = 0; //ans: 정답 수열 길이
    while (l <= r && r < n) {
        if (number[num[r]] + 1 <= k) { //현재 원소를 포함하는 게 k보다 작거나 같다면
            number[num[r]]++; //현재 원소 횟수 증가
            ans = max(ans, r - l + 1); //정답 갱신
            r++;
        } else { //현재 원소를 포함하면 k보다 커진다
            number[num[l]]--; //왼쪽 원소 빼기
            l++;
        }
    }

    cout << ans << '\n';
    return 0;
}