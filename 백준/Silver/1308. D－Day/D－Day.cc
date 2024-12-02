#include <iostream>

using namespace std;

typedef struct Date {
    int y, m, d;
} date;

int getDaysEachMonth(int &m, bool is_leap_year) {
    switch (m) {
        case 2:
            if (is_leap_year) {
                return 29;
            }
            return 28;
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        default:
            return 30;
    }
}

// m1 ~ m2 달 사이의 날짜 구하기
int getDaysBetweenM(int m1, int m2, bool is_leap_year) {
    if (m1 > m2) {
        return 0;
    }
    int day = 0;
    for (int i = m1; i <= m2; i++) {
        day += getDaysEachMonth(i, is_leap_year);
    }
    return day;
}

int getDaysEachYear(int &y, bool is_leap_year) {
    if (is_leap_year) {
        return 366;
    }
    return 365;
}

bool isLeapYear(int y) {
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
        return true;
    }
    return false;
}

// D-Day 구하는 함수
int getDDay(date &curr, date &dest) {
    // 년도랑 달이 같다면
    if (curr.y == dest.y && curr.m == dest.m) {
        return (dest.d - curr.d);
    }
    bool is_leap_curr_y = isLeapYear(curr.y);
    int curr_diff = getDaysEachMonth(curr.m, is_leap_curr_y) - curr.d;
    // 년도만 같다면
    if (curr.y == dest.y) {
        return curr_diff + getDaysBetweenM(curr.m + 1, dest.m - 1, is_leap_curr_y) + dest.d;
    }
    // 다 다르다면
    int day = 0;
    // curr 일 더하기
    day += curr_diff;
    // curr 달 더하기
    day += getDaysBetweenM(curr.m + 1, 12, is_leap_curr_y);
    // 년 더하기
    for (int i = curr.y + 1; i < dest.y; i++) {
        day += getDaysEachYear(i, isLeapYear(i));
    }
    // dest 달 더하기
    bool is_leap_dest_y = isLeapYear(dest.y);
    day += getDaysBetweenM(1, dest.m - 1, is_leap_dest_y);
    // dest 일 더하기
    day += dest.d;
    return day;
}

int main() {
    date curr, dest;

    cin >> curr.y >> curr.m >> curr.d >> dest.y >> dest.m >> dest.d;

    if (curr.y + 1000 < dest.y || (curr.y + 1000 == dest.y && curr.m <= dest.m && curr.d <= dest.d)) {
        cout << "gg";
    } else {
        int d_day = getDDay(curr, dest);
        cout << "D-" << d_day;
    }
    return 0;
}