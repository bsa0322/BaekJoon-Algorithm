#include <iostream>

using namespace std;

/**
 * 미터계 (https://www.acmicpc.net/problem/1862)
 * 현재 값을 기준으로 이전에 4가 총 몇 개 있었을지를 계산해서 n에서 해당 값을 뺌
 * 일의 자리부터 한 자리 씩 돌면서 4의 개수 세기
 * - 각 자리수마다 공식
 *   - 현재 자리수 값이 4보다 크다면
 *     : (이전 자릿수에서 4의 개수(prev_cnt)) * (현재 자리수 값 - 1(4로 시작하는 경우 제외)) + (현재 자릿수에서 4로 시작할 때의 개수(curr_four, 10의 배수))
 *   - 현재 자리수 값이 4보다 작다면
 *     : (이전 자릿수에서 4의 개수) * (현재 자리수 값)
 * - prev_cnt 공식
 *   - prev_cnt = (이전 자릿수에서 4의 개수(prev_cnt)) * 9 + curr_four
 *
 * ex)
 *   - 1769 이 입력일 경우
 *   - minus_cnt = 0 (1769 전에 4가 나온 개수. 즉, 최종적으로 1769에서 해당 변수 값을 뺄 것임)
 *   - 일의 자리 9
 *     - prev_cnt = 0, curr_four = 1 (4)
 *     - minus_cnt += 0 * (9 - 1) + 1 = 1
 *   - 십의 자리 6
 *     - prev_cnt = 1, curr_four = 10 (40 ~ 49)
 *     - minus_cnt += 1 * (6 - 1) + 10 = 1 + 15 = 16
 *   - 백의 자리 7
 *     - prev_cnt = 19, curr_four = 100 (400 ~ 499)
 *     - minus_cnt += 19 * (7 - 1) + 100 = 16 + 214 = 230
 *   - 천의 자리 1
 *     - prev_cnt = 271, curr_four = 1000 (4000 ~ 4999)
 *     - minus_cnt += 271 * 1 = 230 + 271 = 501
 *   => 정답 : 1769 - 501 = 1268
 *
 */

int main() {
    int origin_n;
    cin >> origin_n; // 미터계에 표시된 거리

    int n = origin_n, minus_cnt = 0, curr_four = 1, prev_cnt = 0;
    while (n) {
        int num = n % 10;
        if (num > 4) {
            minus_cnt += (num - 1) * prev_cnt + curr_four;
        } else {
            minus_cnt += num * prev_cnt;
        }

        prev_cnt = prev_cnt * 9 + curr_four;
        curr_four *= 10;
        n /= 10;
    }

    cout << origin_n - minus_cnt;
    return 0;
}