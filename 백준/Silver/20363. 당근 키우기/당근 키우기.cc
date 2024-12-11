#include <iostream>

using namespace std;

int getMinimumCnt(int &x, int &y) {
    if (x < y) {
        swap(x, y);
    }
    return x + (y / 10) + y;
}

/**
 * 온기와 수분 상태가 0이 될 수 없다는 것을 감안해서
 * 온기와 수분 중 더 큰 쪽을 먼저 나머지로 인해 감소되는 것까지 감안해서 채운 후, 나머지 채우기
 */
int main() {
    int x, y;
    cin >> x >> y;

    cout << getMinimumCnt(x, y);
    return 0;
}