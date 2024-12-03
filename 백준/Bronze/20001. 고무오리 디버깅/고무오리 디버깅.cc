#include <iostream>

using namespace std;

int main() {
    int problem = 0;
    string str;
    while (getline(cin, str)) {
        if (str == "고무오리 디버깅 끝") {
            break;
        }
        if (str == "고무오리") {
            if (problem == 0) {
                problem += 2;
            } else {
                problem--;
            }
        } else if (str == "문제") {
            problem++;
        }
    }
    if (problem == 0) {
        cout << "고무오리야 사랑해";
    } else {
        cout << "힝구";
    }
    return 0;
}