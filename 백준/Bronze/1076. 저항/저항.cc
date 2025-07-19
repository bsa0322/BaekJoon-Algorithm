#include <iostream>
#include <map>
#include <vector>

using namespace std;
map<string, int> v, m;

int main() {
    vector<string> colors = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"};
    int m_v = 1;
    for (int i = 0; i < colors.size(); i++) {
        v[colors[i]] = i;
        m[colors[i]] = m_v;
        m_v *= 10;
    }
    string a, b, c;
    cin >> a >> b >> c;
    long long ans = (long long) (10 * v[a] + v[b]) * m[c];
    cout << ans;
    return 0;
}