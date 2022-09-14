//
// Created by BaeSuA on 2022-09-13.
//

#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 500;

int areaSquareTurtle(string cmd) {
    int dx[4] = {0, -1, 0, 1}; //상,좌,하,우
    int dy[4] = {1, 0, -1, 0};

    int direc = 0; //상
    int x = 0, y = 0;
    vector<pair<int, int>> result = {{0, 0}};
    int min_x = SIZE, max_x = -SIZE, min_y = SIZE, max_y = -SIZE;

    for (int i = 0; i < cmd.length(); i++) {
        switch (cmd[i]) {
            case 'F':
                x += dx[direc];
                y += dy[direc];
                result.push_back({x, y});
                break;
            case 'B':
                x -= dx[direc];
                y -= dy[direc];
                result.push_back({x, y});
                break;
            case 'L':
                direc = (direc + 1) % 4;
                break;
            case 'R':
                direc = (direc + 3) % 4;
                break;
        }
    }

    for (int i = 0; i < result.size(); i++) {
        int cx = result[i].first;
        int cy = result[i].second;
        min_x = min(min_x, cx);
        max_x = max(max_x, cx);
        min_y = min(min_y, cy);
        max_y = max(max_y, cy);
    }

    return abs(min_x - max_x) * abs(min_y - max_y);

}

int main() {
    int t;
    string cmd;

    cin >> t;
    while (t--) {
        cin >> cmd;

        // 연산 & 출력
        cout << areaSquareTurtle(cmd) << '\n';
    }
    return 0;
}