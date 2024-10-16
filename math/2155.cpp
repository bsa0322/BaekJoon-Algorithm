#include <iostream>

using namespace std;

// 거리 찾기
int findDist(int &h, int &n) {
    if (h % 2 == 0) {
        if (n % 2 == 0) {
            return 2 * h - 2;
        } else {
            return 2 * h - 3;
        }
    } else {
        if (n % 2 == 0) {
            return 2 * h - 3;
        } else {
            return 2 * h - 2;
        }
    }
}

// 높이 찾기
int findHeight(int &num) {
    int h = 1;
    int temp = 1;
    while (temp <= num) {
        temp += (2 * h - 1);
        h++;
    }
    return h - 1;
}

/**
 * a -> b 까지 가는 값 : (1 -> b 까지 가는 값) - (1 -> a 까지 가는 값)
 * 이떄, 12 -> 13 가는 경우와 같이, a 값에 대한 경로(6)가 b 까지 가는 경로(5)보다 더 클 수 있으므로
 * !! 절댓값 !! 을 씌워야 함을 주의
 *
 * 1 -> n 까지 가는 값 구하는 법
 * - 먼저, n 이 삼각형의 몇 번째 높이에 해당하는지 찾음
 *   => 높이를 h 라 했을 때, 아래와 같은 식이 성립됨
 *   => n = (2*k - 1 for in range(1, h))의 합 + 1
 * - 아래 식에 따라 가장 짧은 경로 길이 정해짐
 *   - h % 2 == 0
 *      - n % 2 == 0 : (h - 1) * 2 = 2 * h - 2
 *      - n % 2 != 0 : (h - 1) * 2 - 1 = 2 * h - 3
 *   - h % 2 != 0
 *      - n % 2 == 0 : 2 * h - 3
 *      - n % 2 != 0 : 2 * h - 2
 */

int main() {
    int a, b;

    cin >> a >> b;

    int a_height = findHeight(a);
    int b_height = findHeight(b);

    int a_dist = findDist(a_height, a);
    int b_dist = findDist(b_height, b);

    cout << abs(b_dist - a_dist);

    return 0;
}