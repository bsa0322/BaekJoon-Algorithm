#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci;

int getMinimumCnt(int &n, vector<ci> &num) {
    int ans = 1;
    int curr_value = num[0].first;
    for (int i = 1; i < n; i++) {
        if (curr_value >= num[i].first && curr_value <= num[i].second) {
            continue;
        }
        if (curr_value > num[i].second) {
            ans++;
        }
        curr_value = num[i].first;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    vector<ci> num(n); // first: 최소, second: 최대
    for (int i = 0; i < n; i++) {
        cin >> num[i].first >> num[i].second;
    }

    cout << getMinimumCnt(n, num);
    return 0;
}