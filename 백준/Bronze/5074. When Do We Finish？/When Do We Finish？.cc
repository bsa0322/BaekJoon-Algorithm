#include <iostream>

using namespace std;
const int DAY = 60 * 24;

string plusFirstZero(string str) {
    if (str.length() == 1) {
        return "0" + str;
    }
    return str;
}

/**
 * 분 단위의 숫자를 HH:MM 형식으로 바꾸는 함수
 */
string numToTime(int &num) {
    int h = num / 60;
    int m = num % 60;
    string hh = plusFirstZero(to_string(h));
    string mm = plusFirstZero(to_string(m));
    return hh + ":" + mm;
}

string minusFirstZero(string str) {
    if (str[0] == '0') {
        return str.substr(1, 1);
    }
    return str;
}

/**
 * HH:MM 형식의 시간을 분 단위의 숫자로 바꾸는 함수
 */
int timeToNum(string &t) {
    string hh = minusFirstZero(t.substr(0, 2));
    string mm = minusFirstZero(t.substr(3, 2));
    int h = stoi(hh);
    int m = stoi(mm);
    return 60 * h + m;
}

int main() {
    string start, duration;
    while (cin >> start >> duration) {
        if (start == "00:00" && duration == "00:00") {
            break;
        }
        int start_t = timeToNum(start);
        int duration_t = timeToNum(duration);
        int end_t = start_t + duration_t;
        int past_day = end_t / DAY;
        end_t %= DAY;
        string end = numToTime(end_t);
        cout << end;
        if (past_day > 0) {
            cout << " +" << past_day;
        }
        cout << '\n';
    }
    return 0;
}