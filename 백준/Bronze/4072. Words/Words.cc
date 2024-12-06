#include <iostream>
#include <algorithm>

using namespace std;

string reverseAllWords(string &str) {
    string temp = "";
    string ans = "";
    for (auto c: str) {
        if (c == ' ') {
            reverse(temp.begin(), temp.end());
            ans += temp + " ";
            temp = "";
            continue;
        }
        temp += c;
    }
    reverse(temp.begin(), temp.end());
    ans += temp;

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;

    while (getline(cin, str)) {
        if (str == "#") {
            break;
        }
        cout << reverseAllWords(str) << '\n';
    }
    return 0;
}