#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getTeamCnt(int &n, int &m, vector<int> &skills) {
    int cnt = 0;
    int left = 0, right = n - 1;
    while (left < right) {
        if (skills[left] + skills[right] >= m) {
            cnt++;
            left++;
            right--;
        } else {
            left++;
        }
    }
    return cnt;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> skills(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> skills[i];
    }
    sort(skills.begin(), skills.end());

    cout << getTeamCnt(n, m, skills);
    return 0;
}