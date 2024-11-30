#include <iostream>
#include <vector>

using namespace std;
typedef struct Bar {
    int l, r, len, d;
} bar;

void debugging(int &curr_t, int &curr_f, bar &c, bar &d, int &tl) {
    cout << "현재 시각: " << curr_t << "\n";
    cout << "층: " << curr_f << '\n';
    vector<bar> temp_floors = {c, d};
    for (int i = 0; i < 2; i++) {
        cout << i << "    ";
        cout << temp_floors[i].l << ' ' << temp_floors[i].r << '\n';
        for (int j = 0; j < temp_floors[i].l; j++) {
            cout << "0 ";
        }
        for (int j = 0; j < temp_floors[i].len; j++) {
            cout << "1 ";
        }
        for (int j = 0; j < tl - temp_floors[i].r - 1; j++) {
            cout << "0 ";
        }
        cout << " 방향: " << temp_floors[i].d << '\n';
    }
    cout << "===========================================\n";
}

// 위 층으로 갈 수 있는지 확인하는 함수
bool isPossibleUp(bar &c, bar &n) {
    if ((c.l >= (n.l - 1) && c.l <= (n.r + 1)) || (c.r >= (n.l - 1) && c.r <= (n.r + 1))) {
        return true;
    }
    if ((n.l >= (c.l - 1) && n.l <= (c.r + 1)) || (n.r >= (c.l - 1) && n.r <= (c.r + 1))) {
        return true;
    }
    return false;
}

// tm 시간이 흐른 후의 막대기 정보
bar getPosOnTime(int &tm, bar &origin, int &tl) {
    if (tm == 0) {
        return origin;
    }
    int diff = tl - origin.len;
    if (diff == 0) {
        return origin;
    }
    bar new_bar = origin;
    int mod = tm % (diff * 2);
    if (mod >= diff) {
        // 방향 바뀜
        new_bar.d = (1 - origin.d);
        mod -= diff;
    }
    if (new_bar.d == 0) {
        // 오른쪽
        new_bar.l = mod;
    } else {
        new_bar.l = tl - origin.len - mod;
    }
    new_bar.r = new_bar.l + origin.len - 1;
    return new_bar;
}

int solution(int &n, int &tl, vector<bar> &floors) {
    int t = 0; // 꼭대기까지 올라가는 데 걸리는 최소 시간
    int curr_f = 0; // 현재 층
    while (true) {
        bar curr_floor = getPosOnTime(t, floors[curr_f], tl);
        for (int i = curr_f; i < n - 1; i++) {
            bar next_floor = getPosOnTime(t, floors[i + 1], tl);
//            debugging(t, i, curr_floor, next_floor, tl);
            if (!isPossibleUp(curr_floor, next_floor)) {
                // 다음 층으로 갈 수 없으면
                break;
            }
            curr_floor = next_floor;
            curr_f = i + 1; // 다음 층 업데이트
        }
        if (curr_f == n - 1) {
            break;
        }
        t++;
    }
    return t;
}

int main() {
    int n, tl; // tl: 전체 길이
    cin >> n >> tl;
    vector<bar> floors(n);
    for (int i = 0; i < n; i++) {
        cin >> floors[i].len >> floors[i].d;
        if (floors[i].d == 0) {
            // 오른쪽
            floors[i].l = 0;
            floors[i].r = floors[i].len - 1;
        } else {
            // 왼쪽
            floors[i].l = tl - floors[i].len;
            floors[i].r = tl - 1;
        }
    }

    cout << solution(n, tl, floors);
    return 0;
}