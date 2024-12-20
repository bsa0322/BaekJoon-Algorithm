#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, string> pis;

bool cmp(const pis &a, const pis &b) {
    if (a.first != b.first) {
        return a.first < b.first;
    }
    if (a.second.length() != b.second.length()) {
        return a.second.length() < b.second.length();
    }
    return a.second < b.second;
}

int main() {
    int n, m, num;
    string str;
    cin >> n >> m;
    vector<int> students(n + 1, 0); // 학급당 체육대회 참가하는 학생 수
    vector<vector<pis>> team(2, vector<pis>(0)); // 0: 백팀, 1: 청팀
    while (cin >> num >> str) {
        if (num == 0 && str == "0") {
            break;
        }
        if (students[num] >= m) {
            // 이미 참여 학생이 m 명 이상이라면 넘어가기
            continue;
        }
        students[num]++;
        int team_num = num % 2;
        team[team_num].push_back({num, str});
    }
    // 청팀부터 출력
    for (int i = 1; i >= 0; i--) {
        // 학급, 학생 이름 순으로 정렬
        sort(team[i].begin(), team[i].end(), cmp);
        for (auto s: team[i]) {
            cout << s.first << ' ' << s.second << '\n';
        }
    }
    return 0;
}