#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, s, t;
    string tag;
    map<string, int> tag_cnt;

    cin >> n;
    while (n--) {
        cin >> s >> t;
        while (t--) {
            cin >> tag;
            tag_cnt[tag]++;
        }
    }

    int max_cnt = 0;
    string max_tag = "";
    bool multiple = false;
    for (auto tag_data: tag_cnt) {
        if (tag_data.second > max_cnt) {
            max_cnt = tag_data.second;
            max_tag = tag_data.first;
            multiple = false;
        } else if (tag_data.second == max_cnt) {
            multiple = true;
        }
    }

    if (multiple) {
        cout << "-1";
    } else {
        cout << max_tag;
    }
    return 0;
}