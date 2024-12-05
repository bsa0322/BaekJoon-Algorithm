#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pi;

// st ~ ed 영역 까지의 그물 안에 속하는 물고기 개수 구하는 함수
int getFishCntWithNet(pi &st, pi &ed, int &m, vector<pi> &fish) {
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        if (fish[i].first >= st.first && fish[i].first <= ed.first && fish[i].second >= st.second &&
            fish[i].second <= ed.second) {
            cnt++;
        }
    }
    return cnt;
}

// 현재 물고기 기준 상, 좌, 좌상 대각선 움직이면서 가능한 시작점 리스트 구하는 함수
vector<pi> getStartPoints(pi &f, int &n, int &l) {
    vector<pi> st_points = {f}; // 현재 물고기 위치
    int dr[3] = {-1, 0, -1};
    int dc[3] = {0, -1, -1};
    for (int i = 1; i < l / 2; i++) {
        for (int j = 0; j < 3; j++) {
            int nr = f.first + dr[j] * i;
            int nc = f.second + dc[j] * i;
            if (nr < 1 || nc < 1) {
                continue;
            }
            st_points.emplace_back(nr, nc);
        }
    }
    return st_points;
}

// 길이가 l일 때 칠 수 있는 그물 범위 {세로, 가로} 리스트 구하는 함수
vector<pi> getNets(int &l) {
    vector<pi> nets;
    int half_l = l / 2;
    for (int i = 1; i < half_l; i++) {
        nets.emplace_back(i, half_l - i);
    }
    return nets;
}

int getMaximumFish(int &n, int &l, int &m, vector<pi> &fish) {
    int ans = 0;
    vector<pi> nets = getNets(l); // 가능한 그물들 {세로, 가로}
    int nets_size = nets.size();

    // 모든 물고기를 시작 점으로 가능한 모든 그물을 쳤을 때, 물고기 수 구해서 비교
    for (int i = 0; i < fish.size(); i++) {
        vector<pi> st_points = getStartPoints(fish[i], n, l);
        for (int j = 0; j < st_points.size(); j++) {
            pi st = st_points[j];
            for (int k = 0; k < nets_size; k++) {
                pi ed = {st.first + nets[k].first, st.second + nets[k].second};
                if (ed.first > n || ed.second > n) {
                    // 범위 벗어가는 그물은 치지 않음
                    continue;
                }

                int curr_cnt = getFishCntWithNet(st, ed, m, fish);
                ans = max(ans, curr_cnt);
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, l, m;

    cin >> n >> l >> m;
    vector<pi> fish(m);
    for (int i = 0; i < m; i++) {
        cin >> fish[i].first >> fish[i].second;
    }

    cout << getMaximumFish(n, l, m, fish);
    return 0;
}