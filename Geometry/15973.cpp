#include <iostream>

using namespace std;

bool isPoint(int &x1, int &y1, int &x2, int &y2, int &x3, int &y3, int &x4, int &y4) {
    if (x2 == x3 && y2 == y3) { // 오른쪽 위
        return true;
    }
    if (x1 == x4 && y2 == y3) { // 왼쪽 위
        return true;
    }
    if (x1 == x4 && y1 == y4) { // 왼쪽 아래
        return true;
    }
    if (x2 == x3 && y1 == y4) { // 오른쪽 아래
        return true;
    }
    return false;
}

bool isLine(int &x1, int &y1, int &x2, int &y2, int &x3, int &y3, int &x4, int &y4) {
    if (x2 == x3 && y3 <= y2 && y4 >= y1) { // 오른쪽
        return true;
    }
    if (y2 == y3 && x3 <= x2 && x4 >= x1) { // 위쪽
        return true;
    }
    if (x1 == x4 && y3 <= y2 && y4 >= y1) { // 왼쪽
        return true;
    }
    if (y1 == y4 && x3 <= x2 && x4 >= x1) { // 아래쪽
        return true;
    }
    return false;
}

bool isFace(int &x1, int &y1, int &x2, int &y2, int &x3, int &y3, int &x4, int &y4) {
    if ((x4 >= x1 && x4 <= x2) || (x3 >= x1 && x3 <= x2)) { // 세로
        if (y4 >= y1 && y3 <= y2) {
            return true;
        }
    }
    if ((y4 >= y1 && y4 <= y2) || (y3 >= y1 && y3 <= y2)) { // 가로
        if (x4 >= x1 && x3 <= x2) {
            return true;
        }
    }
    if (x1 >= x3 && x4 >= x2 && y1 >= y3 && y4 >= y2) { // 바깥에
        return true;
    }
    if (x1 <= x3 && x4 <= x2 && y1 <= y3 && y4 <= y2) { // 안에
        return true;
    }
    return false;
}

int main() {
    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    if (isPoint(x1, y1, x2, y2, x3, y3, x4, y4)) {
        cout << "POINT";
    } else if (isLine(x1, y1, x2, y2, x3, y3, x4, y4)) {
        cout << "LINE";
    } else if (isFace(x1, y1, x2, y2, x3, y3, x4, y4)) {
        cout << "FACE";
    } else {
        cout << "NULL";
    }
    return 0;
}