#include <iostream>

using namespace std;

bool isPoint(int x1, int y1, int p1, int q1, int x2, int y2, int p2, int q2) {
    if (x1 == p2 && q1 == y2) {
        return true;
    }
    if (p1 == x2 && q1 == y2) {
        return true;
    }
    if (x1 == p2 && y1 == q2) {
        return true;
    }
    if (p1 == x2 && y1 == q2) {
        return true;
    }
    return false;
}

bool isLine(int x1, int y1, int p1, int q1, int x2, int y2, int p2, int q2) {
    if (q1 == y2 && x2 < p1 && p2 > x1) { // 상
        return true;
    }
    if (p1 == x2 && y2 < q1 && q2 > y1) { // 우
        return true;
    }
    if (y1 == q2 && x2 < p1 && p2 > x1) { // 하
        return true;
    }
    if (x1 == p2 && y2 < q1 && q2 > y1) { // 좌
        return true;
    }
    return false;
}

bool isFace(int x1, int y1, int p1, int q1, int x2, int y2, int p2, int q2) {
    if (y2 < q1 && q2 > y1 && x2 < p1 && p2 > x1) { // 상, 하, 좌, 우
        return true;
    }
    // 2가 1에 완전히 포개짐
    if(x1 <= x2 && p2 <= p1 && y1 <= y2 && q2 <= q1){
        return true;
    }
    // 1이 2에 완전히 포개짐
    if(x1 >= x2 && p2 >= p1 && y1 >= y2 && q2 >= q1){
        return true;
    }
    return false;
}

/**
 * https://www.acmicpc.net/problem/15973 랑 똑같은 문제
 * @return
 */

int main() {
    int x1, y1, p1, q1, x2, y2, p2, q2;

    for (int i = 0; i < 4; i++) {
        cin >> x1 >> y1 >> p1 >> q1 >> x2 >> y2 >> p2 >> q2;
        if (isPoint(x1, y1, p1, q1, x2, y2, p2, q2)) {
            cout << "c\n";
        } else if (isLine(x1, y1, p1, q1, x2, y2, p2, q2)) {
            cout << "b\n";
        } else if (isFace(x1, y1, p1, q1, x2, y2, p2, q2)) {
            cout << "a\n";
        } else {
            cout << "d\n";
        }
    }
    return 0;
}