#include <iostream>
#include <vector>

using namespace std;

bool isMountain(int &n, vector<int> &num) {
    if (n == 1) {
        return true;
    }
    bool increase = true;
    for (int i = 0; i < n - 1; i++) {
        if (num[i] == num[i + 1]) { // 같으면 바로 false 리턴
            return false;
        }
        if (increase && num[i] > num[i + 1]) {
            // 처음으로 감소하는 부분
            increase = false;
            continue;
        }
        if (!increase && num[i] < num[i + 1]) {
            // 계속 감소해야 하는데, 증가하는 부분이 다시 나온다면 바로 false 리턴
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    cout << (isMountain(n, num) ? "YES" : "NO");
    return 0;
}