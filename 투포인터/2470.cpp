#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;
long long int liquid[100010];

int main() {
    long long int n, l = 0, r, sum, ans = 10000000000, id1, id2;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> liquid[i];
    }
    sort(liquid, liquid + n);
    r = n - 1;
    while (l < r) {
        sum = liquid[l] + liquid[r];
        if (abs(sum) < abs(ans)) {
            ans = sum;
            id1 = l;
            id2 = r;
        }

        if (sum < 0)
            l++;
        else
            r--;
    }
    cout << liquid[id1] << ' ' << liquid[id2] << '\n';
    return 0;
}