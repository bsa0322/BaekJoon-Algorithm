#include <iostream>

using namespace std;

bool isFace(int x, int y, int x1, int y1, int x2, int y2) {
    if (x > x1 && x < x2 && y < y2)
        return true;
    else if (y > y1 && y < y2 && x < x1)
        return true;
    return false;
}

bool isLine(int x1, int y1, int x2, int y2) {
    if (x1 == x2 || y1 == y2)
        return true;
    return false;
}

bool isPoint(int x1, int y1, int x2, int y2) {
    if (x1 == x2 && y1 == y2)
        return true;
    return false;
}

int main() {
    int x1, y1, x2, y2; //박스1
    int a1, b1, a2, b2; //박스2

    //입력
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> a1 >> b1 >> a2 >> b2;

    //연산
    if (isPoint(x2, y2, a1, b1) || isPoint(x1, y2, a2, b1) || isPoint(x1, y1, a2, b2) || isPoint(x2, y1, a1, b2))
        cout << "POINT\n";
    else if (isLine(x2, y2, a1, b1) || isLine(x1, y2, a2, b1) || isLine(x1, y1, a2, b2) || isLine(x2, y1, a1, b2))
        cout << "LINE\n";
    else if (isFace(a1, b1, x1, y1, x2, y2) || isFace(a2, b1, x1, y1, x2, y2) || isFace(a2, b2, x1, y1, x2, y2) ||
             isFace(a1, b2, x1, y1, x2, y2))
        cout << "FACE\n";
    else
        cout << "NULL\n";
    return 0;
}