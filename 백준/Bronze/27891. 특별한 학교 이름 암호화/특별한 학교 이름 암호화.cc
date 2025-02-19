#include <iostream>
#include <map>

using namespace std;

int main() {
    map<string, string> school;
    school["NLCS"] = "northlondo";
    school["BHA"] = "branksomeh";
    school["KIS"] = "koreainter";
    school["SJA"] = "stjohnsbur";

    string input;
    cin >> input;
    for (auto s: school) {
        string name = s.first;
        string plain = s.second;
        int n = plain[0] - input[0];
        bool flag = true;
        for (int i = 1; i < 10; i++) {
            int decrypt = input[i] + n;
            if (decrypt > 'z') {
                decrypt -= 26;
            } else if (decrypt < 'a') {
                decrypt += 26;
            }
            if (plain[i] != decrypt) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << name;
            break;
        }
    }
    return 0;
}