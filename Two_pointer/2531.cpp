#include <iostream>
#include <vector>

using namespace std;

int sushi(int n, int d, int k, int c, vector<int> &num) {
    vector<int> number(d + 1, 0);
    int cnt = 1;
    number[c] = 1;
    for (int i = 0; i < k; i++) {
        if (number[num[i]] == 0)
            cnt++;
        number[num[i]]++;
    }
    int ans = cnt;
    for (int i = 0; i < n; i++) { //순서 완전 중요! 꼭 왼쪽 처리하고, 오른쪽 처리해야함, 안그럼 16% 계속 틀림
        if (number[num[i]] == 1)
            cnt--;
        number[num[i]]--;
        if (number[num[(k + i) % n]] == 0)
            cnt++;
        number[num[(k + i) % n]]++;

        ans = max(ans, cnt);
    }

    return ans;
}

int main() {
    int n, d, k, c;

    cin >> n >> d >> k >> c;
    vector<int> num(n, 0);
    for (int i = 0; i < n; i++)
        cin >> num[i];

    cout << sushi(n, d, k, c, num) << '\n';

    return 0;
}