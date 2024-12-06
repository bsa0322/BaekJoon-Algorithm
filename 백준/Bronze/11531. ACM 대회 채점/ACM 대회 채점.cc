#include <iostream>
#include <vector>
#include <map>

using namespace std;
typedef pair<int, int> pi;
typedef struct Info {
    int t;
    char problem;
    string result;
} info;

pi getScorePenalty(vector<info> &logs) {
    map<char, int> wrong_cnt;
    int score = 0;
    int penalty = 0;
    for (int i = 0; i < logs.size(); i++) {
        if (logs[i].result == "wrong") {
            wrong_cnt[logs[i].problem]++;
        } else if (logs[i].result == "right") {
            score++;
            penalty += (logs[i].t + wrong_cnt[logs[i].problem] * 20);
        }
    }
    return {score, penalty};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    info data;
    vector<info> logs;
    while (cin >> data.t) {
        if (data.t == -1) {
            break;
        }
        cin >> data.problem >> data.result;
        logs.push_back(data);
    }

    pi result = getScorePenalty(logs);
    cout << result.first << ' ' << result.second;
    return 0;
}