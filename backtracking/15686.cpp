#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pi;
const int INF = 2e9;

int answer = INF;
vector<pi> choose;

int getDistance(int &cnt, vector<pi> &house) {
    int distance = 0;
    for (int i = 0; i < house.size(); i++) {
        int temp_d = INF;
        for (int j = 0; j < cnt; j++) {
            temp_d = min(temp_d, abs(house[i].first - choose[j].first) + abs(house[i].second - choose[j].second));
        }
        distance += temp_d;
    }
    return distance;
}

void backtracking(int cnt, int t, int &n, int &m, vector<pi> &house, vector<pi> &chicken) {
    if (cnt > 0 && cnt <= m) {
        int dist = getDistance(cnt, house);
        answer = min(answer, dist);
        if (cnt == m) {
            return;
        }
    }

    for (int i = t; i < chicken.size(); i++) {
        choose[cnt] = chicken[i];
        backtracking(cnt + 1, i + 1, n, m, house, chicken);
        choose[cnt] = {-1, -1};
    }
}

/**
 * 폐업시키지 않을 치킨집을 최대 M개 골랐을 때, 도시의 치킨 거리의 최솟값
 */
int main() {
    int n, m, num;
    cin >> n >> m;

    choose.assign(m, {-1, -1});
    // 치킨 집 & 집 포지션 저장
    vector<pi> chicken, house;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> num;
            if (num == 1) {
                house.emplace_back(i, j);
            } else if (num == 2) {
                chicken.emplace_back(i, j);
            }
        }
    }

    backtracking(0, 0, n, m, house, chicken);

    cout << answer;
    return 0;
}