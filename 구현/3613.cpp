#include <iostream>

using namespace std;

bool checkCpp(string s) {
    bool check = true; //언더바 체크
    for (int i = 0; i < s.length(); i++) {
        if ((check && s[i] == '_') || isupper(s[i]) ||
            (i == s.length() - 1 && s[i] == '_')) //언더바 연속 or 대문자 or 마지막 문자 언더바 나오면
            return false;
        if (!check && s[i] == '_')
            check = true;
        else
            check = false;
    }
    return true;
}

bool checkJava(string s) {
    for (int i = 0; i < s.length(); i++) {
        if ((!i && isupper(s[i])) || s[i] == '_') //처음에 대문자 or 언더바 나오면
            return false;
    }
    return true;
}

string cppToJava(string s) {
    string java = "";
    bool check = false; //언더바 체크
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '_') {
            check = true;
            continue;
        }
        if (check) {
            java += toupper(s[i]);
            check = false;
            continue;
        }
        java += s[i];
    }

    return java;
}

string javaToCpp(string s) {
    string cpp = "";
    for (int i = 0; i < s.length(); i++) {
        if (isupper(s[i])) {
            cpp += '_';
            cpp += tolower(s[i]);
            continue;
        }
        cpp += s[i];
    }

    return cpp;
}

int main() {
    string s;
    cin >> s;

    if (checkCpp(s) && checkJava(s))
        cout << s << '\n';
    else if (checkCpp(s))
        cout << cppToJava(s) << '\n';
    else if (checkJava(s))
        cout << javaToCpp(s) << '\n';
    else
        cout << "Error!\n";

    return 0;
}