#include <iostream>
#include <vector>

using namespace std;
typedef pair<string, string> ps;

int main() {
    int n;
    string str, type, t_h, t_m;
    vector<ps> st;

    cin >> n;
    for (int i = 0; i < n + 1; i++) {
        cin >> str >> type;
        string h = str.substr(0, 2);
        string m = str.substr(3, 2);
        if (type == "teacher") {
            t_h = h;
            t_m = m;
        } else {
            st.emplace_back(h, m);
        }
    }
    cin >> str;
    string l_h = str.substr(0, 2);
    string l_m = str.substr(3, 2);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (l_h > st[i].first || (l_h == st[i].first && l_m > st[i].second)) {
            continue;
        }
        if (t_h > st[i].first || (t_h == st[i].first && t_m > st[i].second)) {
            continue;
        }
        ans++;
    }
    cout << ans;
    return 0;
}