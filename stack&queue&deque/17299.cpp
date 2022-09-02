//
// Created by cse_asus on 2022-09-02.
//
//역방향
//#include <iostream>
//#include <vector>
//#include <stack>
//
//using namespace std;
//const int SIZE = 1e6;
//
///**
// * 오등큰 수: 자신보다 오른쪽에 있는 수 중 빈도수가 더 큰 수인데 가장 왼쪽
// *
// * [시간초과]
// * 배열 정방향 순회하면서 현재 원소 값의 빈도수가 stack의 top에 있는 원소보다 크다면 stack에 있는 원소들의 result모두 갱신하는 방식
// * -> O(n^2)이라 시간초과인듯?
// * + map 쓰면 시간초과,,,,,,,,,,,,,접근하는 데 그래도 logN이 걸리니까!! 난 바보다
// * 무조건 vector 사용해야함...^^
// *
// * 역방향으로 순회하고,, 스택의 top엔 항상 큰 얘를 저장? 근데 더 작더라도 왼쪽에 있는 수여서 해당될지도 흠
// * -> 오등큰수를 가진 얘만 저장!?
// * -> 현재 탐색하는 원소의 빈도수보다 오른쪽에 작은 것들이 있다면 모두 삭제
// *
// * 결국 방향은 상관없었다..
// */
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    int n;
//    vector<int> cnt(SIZE + 1, 0);
//    stack<int> st;
//
//    cin >> n;
//    vector<int> arr(n, 0), result(n, -1);
//    for (int i = 0; i < n; i++) {
//        cin >> arr[i];
//        cnt[arr[i]]++;
//    }
//
//    st.push(n - 1);
//    for (int i = n - 2; i >= 0; i--) {
//        int first = arr[i];
//        int second = cnt[first];
//        while (!st.empty() && cnt[arr[st.top()]] <= second) {
//            st.pop();
//        }
//        if (!st.empty()) {
//            result[i] = arr[st.top()];
//        }
//        st.push(i);
//    }
//
//    for (int i = 0; i < n; i++) {
//        cout << result[i] << ' ';
//    }
//
//    return 0;
//}
//
// Created by cse_asus on 2022-09-02.
//
//정방향
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
const int SIZE = 1e6;

/**
 * 오등큰 수: 자신보다 오른쪽에 있는 수 중 빈도수가 더 큰 수인데 가장 왼쪽
 */

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    vector<int> cnt(SIZE + 1, 0);
    stack<int> st;

    cin >> n;
    vector<int> arr(n, 0), result(n, -1);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        cnt[arr[i]]++;
    }

    for (int i = 0; i < n; i++) {
        int first = arr[i];
        int second = cnt[first];
        while (!st.empty() && cnt[arr[st.top()]] < second) {
            result[st.top()] = first;
            st.pop();
        }
        st.push(i);
    }

    for (int i = 0; i < n; i++) {
        cout << result[i] << ' ';
    }

    return 0;
}