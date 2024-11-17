#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pi;
typedef pair<pi, pi> ppi;

const int INF = 5e5;

// 힘
const int SAME = 1;
const int ORIGIN = 2;
const int CONNECT = 3;
const int OPPOSITE = 4;

// 인접 인덱스인지 확인
bool isConnect(int d1, int d2) {
    if (d1 == 0 || d2 == 0) {
        return false;
    }
    int d1_right = ((d1 - 1) + 1) % 4 + 1;
    int d1_left = ((d1 - 1) + 3) % 4 + 1;
    if (d1_left == d2 || d1_right == d2) {
        return true;
    }
    return false;
}

// 반대 인덱스인지 확인
bool isOpposite(int d1, int d2) {
    if (d1 == 0 || d2 == 0) {
        return false;
    }
    int d1_opposite = (d1 + 2) % 4;
    if (d1_opposite == 0) {
        d1_opposite = 4;
    }
    return d1_opposite == d2;
}

int getMinimumPower(vector<int> &commands) {
    int n = commands.size() - 1;
    vector<vector<vector<int>>> dist(n + 1, vector<vector<int>>(5, vector<int>(5, INF)));
    priority_queue<ppi, vector<ppi>, greater<>> pq;

    int ans = INF;
    pq.push({{0, 0},
             {0, 0}});
    dist[0][0][0] = 0;
    while (!pq.empty()) {
        int curr_p = pq.top().first.first;
        int curr_idx = pq.top().first.second;
        int curr_l = pq.top().second.first;
        int curr_r = pq.top().second.second;
        int next_idx = curr_idx + 1;
        pq.pop();

//        cout << curr_idx << ' ' << curr_p << ' ' << curr_l << ' ' << curr_r << '\n';

        if (dist[curr_idx][curr_l][curr_r] < curr_p) {
            continue;
        }
        if (curr_idx == n) {
            ans = min(ans, curr_p);
            continue;
        }
//        cout << "탐색" << '\n';

        // 동일한 점 이동
        if (curr_l == commands[next_idx] || curr_r == commands[next_idx]) {
            if (dist[next_idx][curr_l][curr_r] > curr_p + SAME) {
                dist[next_idx][curr_l][curr_r] = curr_p + SAME;
                pq.push({{curr_p + SAME, next_idx},
                         {curr_l,        curr_r}});
            }
        }

        // 제자리 이동
        if (curr_l == 0 && commands[next_idx] != curr_r) {
            if (dist[next_idx][commands[next_idx]][curr_r] > curr_p + ORIGIN) {
                dist[next_idx][commands[next_idx]][curr_r] = curr_p + ORIGIN;
                pq.push({{curr_p + ORIGIN,    next_idx},
                         {commands[next_idx], curr_r}});
            }
        }
        if (curr_r == 0 && commands[next_idx] != curr_l) {
            if (dist[next_idx][curr_l][commands[next_idx]] > curr_p + ORIGIN) {
                dist[next_idx][curr_l][commands[next_idx]] = curr_p + ORIGIN;
                pq.push({{curr_p + ORIGIN, next_idx},
                         {curr_l,          commands[next_idx]}});
            }
        }

        // 인접 이동
        if (isConnect(curr_l, commands[next_idx]) && curr_r != commands[next_idx]) {
            if (dist[next_idx][commands[next_idx]][curr_r] > curr_p + CONNECT) {
                dist[next_idx][commands[next_idx]][curr_r] = curr_p + CONNECT;
                pq.push({{curr_p + CONNECT,   next_idx},
                         {commands[next_idx], curr_r}});
            }
        }
        if (isConnect(curr_r, commands[next_idx]) && curr_l != commands[next_idx]) {
            if (dist[next_idx][curr_l][commands[next_idx]] > curr_p + CONNECT) {
                dist[next_idx][curr_l][commands[next_idx]] = curr_p + CONNECT;
                pq.push({{curr_p + CONNECT, next_idx},
                         {curr_l,           commands[next_idx]}});
            }
        }

        // 반대 이동
        if (isOpposite(curr_l, commands[next_idx]) && curr_r != commands[next_idx]) {
            if (dist[next_idx][commands[next_idx]][curr_r] > curr_p + OPPOSITE) {
                dist[next_idx][commands[next_idx]][curr_r] = curr_p + OPPOSITE;
                pq.push({{curr_p + OPPOSITE,  next_idx},
                         {commands[next_idx], curr_r}});
            }
        }
        if (isOpposite(curr_r, commands[next_idx]) && curr_l != commands[next_idx]) {
            if (dist[next_idx][curr_l][commands[next_idx]] > curr_p + OPPOSITE) {
                dist[next_idx][curr_l][commands[next_idx]] = curr_p + OPPOSITE;
                pq.push({{curr_p + OPPOSITE, next_idx},
                         {curr_l,            commands[next_idx]}});
            }
        }
    }

    return ans;
}

/**
 * 좀 더 일찍 맞힐 수 있었는데 !! 아쉽....
 * 최단경로로 접근 -> dist거리 저장할 때, 명령 순서만 고려하는 게 아니라 (l, r)에 대한 값도 저장해서 3차원으로 관리
 * => 여기까지 했으면 맞아야 하는건데 !! dist 확인할 때, curr_idx로 보고 있었어서 틀림.. next_idx로 해야 하는걸 !!다음 날 보니까 이게 보이네.. 억울...
 * @return
 */

int main() {
    int cmd;

    vector<int> commands(1, 0); // 더미 인덱스 0
    while (cin >> cmd) {
        if (cmd == 0) {
            break;
        }
        commands.push_back(cmd);
    }

    cout << getMinimumPower(commands);

    return 0;
}