#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll getPossibleMaxSize(int &n, int &m, vector<int> &arr) {
    int left = 0, right = 0;
    ll sum = 0, ans = 0;
    while (right < n) {
        ll new_sum = sum + arr[right];
        if (new_sum <= m) {
            right++;
            sum = new_sum;
            ans = max(ans, sum);
        } else {
            sum -= arr[left];
            left++;
            if (left > right) {
                right = left;
                sum = 0;
            }
        }
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << getPossibleMaxSize(n, m, arr);
    return 0;
}