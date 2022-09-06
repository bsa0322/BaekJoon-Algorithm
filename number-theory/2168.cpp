//
// Created by BaeSuA on 2022-09-06.
//

#include <iostream>

using namespace std;
typedef long long ll;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

/**
 * 가로 x, 세로 y (x,y 서로소, x < y) 일 때, 대각선 칸 개수 공식
 * -> 가로에 칸이 1칸 차지하는 세로 행 개수(one) = (y-x)+1
 * -> 전체 대각선 칸 개수 = one + 2*(y-one)
 *
 * 따라서 두 수 최대공약수 구한 후, 가장 작은 x*y쌍 찾아서 대각선 칸 수 구한 다음 최대공약수를 곱한다
 */

int main() {
    int x, y;

    // 입력
    cin >> x >> y;
    int g = gcd(x, y);

    int small_x = x / g;
    int small_y = y / g;

    if (small_x > small_y) {
        swap(small_x, small_y);
    }

    ll one = small_y - small_x + 1;

    ll small_ans = one + 2 * (small_y - one);
    ll ans = small_ans * g;

    cout << ans;
    return 0;
}