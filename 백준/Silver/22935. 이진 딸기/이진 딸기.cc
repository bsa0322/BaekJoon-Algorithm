#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const string STRAWBERRY = "딸기";
const string REST = "V";

// 딸기 문자열 구하는 함수
string getStr(int n) {
    int cnt = 0;
    vector<string> arr;
    while (n) {
        if (n % 2 == 1) {
            arr.push_back(STRAWBERRY);
        } else {
            arr.push_back(REST);
        }
        n /= 2;
        cnt++;
    }
    // V 추가
    for (int i = 0; i < (4 - cnt); i++) {
        arr.push_back(REST);
    }
    reverse(arr.begin(), arr.end());
    string ans = "";
    for (int i = 0; i < arr.size(); i++) {
        ans += arr[i];
    }
    return ans;
}

// 1 ~ 15 사이로 차례 구하는
int getNum(int &n) {
    int mod = n % 28;
    if (mod == 0) {
        mod = 28;
    }
    if (mod > 15) {
        return (30 - mod);
    }
    return mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << getStr(getNum(n)) << '\n';
    }
    return 0;
}