#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll countPeople(ll &t, int &m, vector<int> &times) {
    ll cnt = 0;
    for (int i = 0; i < times.size(); i++) {
        ll curr_cnt = t / times[i];
        if (curr_cnt == 0) {
            break;
        }
        cnt += curr_cnt;
        if (cnt > m) {
            // 오버플로우 방지
            // m 보다 많아진다면 그냥 멈추기
            break;
        }
    }
    return cnt;
}

/**
 * 입국심사 (https://www.acmicpc.net/problem/3079)
 *
 * parametric search 문제인데
 * 30% 정도에서 틀렸습니다..
 *
 * 아무래도 정답 초가 연속적인 관계는 아니라서.. 나눠 떨어지는 게 있는지 확인해야 하는듯
 * 오잉 이거 처리했는데도 틀렸습니다..라면 이게 문제가 아닌가 ??
 * 하긴 계속 왼쪽으로 오다보면 딱 나눠떨어지는 가장 작은 곳에서 멈추긴 할듯
 *
 * (질문 게시판 참고) 해당 초에서 가능한 명 수 계산하는 부분에서 m보다 넘어가면 long long 범위로도 오버플로우 되는 경우 발생..!!
 * -> 그래서 중간에 m 넘어간다면 바로 break
 */

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> times(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> times[i];
    }

    sort(times.begin(), times.end());

    ll left = 1;
    ll right = 1e18;
    while (left <= right) {
        ll mid = (left + right) / 2;
        ll cnt = countPeople(mid, m, times);

        if (cnt >= m) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << left;
    return 0;
}