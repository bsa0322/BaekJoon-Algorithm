#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, x;
    int ans = 0;

    cin >> n >> x;
    int num;
    vector<int> sum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> num;
        sum[i] = sum[i - 1] + num;
    }

    int mx = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (i - x < 0)
            continue;
        if (mx < sum[i] - sum[i - x]) {
            mx = sum[i] - sum[i - x];
            cnt = 1;
        } else if (mx == sum[i] - sum[i - x])
            cnt++;
    }
    /*
    vector<int> num(n, 0);
    for (int i = 0; i < n; i++)
        cin >> num[i];

    //슬라이딩 윈도우
    int l = 0, r = 0, sum = 0, mx = 0, cnt = 0;
    while (r < n) {
        if (r - l < x)
            sum += num[r++];
        else
            sum -= num[l++];

        if (mx == sum)
            cnt++;
        else if (mx < sum) {
            mx = sum;
            cnt = 1;
        }
    }
    */

    if (!mx) //0이라면
        cout << "SAD\n";
    else
        cout << mx << '\n' << cnt << '\n';

    return 0;
}