#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
long long ans = 1e9 * 3 + 1;
int id1, id2, id3;

vector<long long> num;

void liquid(int n, int fixed, long long sum) {
    int left = fixed + 1, right = n - 1;
    while (true) {
        if (left >= right)
            break;
        long long mix = sum + num[left] + num[right];
        if (abs(mix) < ans) {
            ans = abs(mix);
            id1 = fixed;
            id2 = left;
            id3 = right;
        }
        if (mix < 0) {
            left++;
        } else if (mix > 0) {
            right--;
        } else //이거 없으면 시간초과
            break;
    }
}

int main() {
    cin.tie(0);
    int n;

    //입력
    cin >> n;
    num.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> num[i];

    //연산
    sort(num.begin(), num.end());
    for (int i = 0; i < n - 2; i++) {
        liquid(n, i, num[i]);
    }

    //출력
    vector<long long> result = {num[id1], num[id2], num[id3]};
    for (int i = 0; i < 3; i++)
        cout << result[i] << ' ';

    return 0;
}