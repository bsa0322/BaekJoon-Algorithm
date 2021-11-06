//"가장 긴 증가하는 부분 수열" 문제 역추적
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;

/**
 * 강의자료 점화식
 *
 * 시간 복잡도 O(n^2)
 */
ci lis(int n, vector<int> &arr, vector<int> &path) {
    vector<int> dp(n, 1);
    ci ans = {1, 0}; //최장 길이, 마지막 원소 인덱스

    for (int i = 1; i < n; i++) {
        int index = -1; //중간 경로 저장할 변수
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) { //증가하는 관계 + (dp[j] + 1)이 더 크다면
                dp[i] = dp[j] + 1;
                index = j;
            }
        }
        path[i] = index;
        if (ans.first < dp[i]) //최장 길이 + 마지막 원소 인덱스 갱신
            ans = {dp[i], i};
    }
    return ans;
}

int main() {
    int n;

    //입력
    cin >> n;
    vector<int> arr(n);
    vector<int> path(n, -1);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    //연산
    ci ans = lis(n, arr, path);
    vector<int> result(0);
    int x = ans.second;
    while (x != -1) {
        result.push_back(x);
        x = path[x];
    }

    //출력
    cout << ans.first << '\n';
    for (int i = result.size() - 1; i >= 0; i--)
        cout << arr[result[i]] << ' ';
    return 0;
}