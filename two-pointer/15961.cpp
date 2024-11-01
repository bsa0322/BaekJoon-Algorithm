#include <iostream>
#include <vector>

using namespace std;

int getMaximumTypeCnt(int &n, int &d, int &k, int &c, vector<int> &sushi) {
    vector<int> sushi_cnt(d + 1, 0);
    int cnt = 1;

    // 쿠폰 초밥 미리 먹기
    sushi_cnt[c] = 1;

    // 윈도우 초기화
    for (int i = 0; i < k; i++) {
        int sushi_num = sushi[i];
        if (sushi_cnt[sushi_num] == 0) {
            cnt++;
        }
        sushi_cnt[sushi_num]++;
    }
    int ans = cnt;

    // 슬라이딩 윈도우
    for (int i = k; i < n + k; i++) {
        int right_sushi = sushi[i % n];
        int left_sushi = sushi[i - k];

        // 왼쪽 빼고 오른쪽 추가
        sushi_cnt[left_sushi]--;
        if (sushi_cnt[left_sushi] == 0) {
            cnt--;
        }
        if (sushi_cnt[right_sushi] == 0) {
            cnt++;
        }
        sushi_cnt[right_sushi]++;

        ans = max(ans, cnt);
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, d, k, c;
    cin >> n >> d >> k >> c;
    vector<int> sushi(n);
    for (int i = 0; i < n; i++) {
        cin >> sushi[i];
    }

    cout << getMaximumTypeCnt(n, d, k, c, sushi);
    return 0;
}