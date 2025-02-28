#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int w;
    while (true) {
        char s, c;
        map<char, vector<int>> mp;
        vector<char> size_vector = {'S', 'M', 'L'};
        for (int i = 0; i < 3; i++) {
            mp[size_vector[i]] = vector<int>(26, 0);
        }
        cin >> w;
        if (w == 0) {
            break;
        }
        while (w--) {
            cin >> s >> c;
            mp[s][c - 'A']++;
        }
        cin >> w;
        while (w--) {
            cin >> s >> c;
            mp[s][c - 'A']++;
        }
        for (int i = 0; i < 3; i++) {
            char size = size_vector[i];
            vector<int> colors = mp[size];
            for (int j = 0; j < 26; j++) {
                while (colors[j]--) {
                    cout << size << char(j + 'A') << ' ';
                }
            }
        }
        cout << '\n';
    }
    return 0;
}